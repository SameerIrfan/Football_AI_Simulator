// Fill out your copyright notice in the Description page of Project Settings.


#include "FootballPlayer.h"

#include "AnimationComponent.h"
#include "AttributeComponent.h"
#include "NavigationSystem.h"
#include "TimerManager.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"
#include "Football/DebugMacros.h"
#include "Football/AI/FootballAIController.h"
#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Teams/Team.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AFootballPlayer::AFootballPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	GetMesh()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);

	BallHoldComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallHoldComponent"));
	BallHoldComponent->SetupAttachment(GetMesh());

	PlayerSelectedMark = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerSelectedMark"));
	PlayerSelectedMark->SetupAttachment(GetMesh());
	
	PlayerDirectionArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerDirectionArrow"));
	PlayerDirectionArrow->SetupAttachment(GetRootComponent());
	
	Attributes = CreateDefaultSubobject<UAttributeComponent>(TEXT("Attributes"));
	Animator = CreateDefaultSubobject<UAnimationComponent>(TEXT("Animator"));
	
}

void AFootballPlayer::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MatchStartTime = FPlatformTime::Seconds();
	FindTargetLocation();
}

void AFootballPlayer::LookTo(FVector TargetLocation)
{
	FVector MyLocation = GetActorLocation();
	TargetLocation.Z = MyLocation.Z;
	FRotator ToRot = UKismetMathLibrary::FindLookAtRotation(MyLocation, TargetLocation);
	FRotator NewRot = FMath::RInterpTo(GetActorRotation(), ToRot, 0.1f, 5);
	RootComponent->SetWorldRotation(ToRot);
}

void AFootballPlayer::Struggle()
{
	if( CurrentAct == EActs::Stunned) return;
	
	if( IsHoldingBall )
	{
		Ball->Release();
	}
	
	CurrentAct = EActs::Stunned;
	Animator->PlayRandomMontageSection(Animator->BallLoseMontage, Animator->BallLoseMontageSections);

	UpdateActionStartTime(CurrentAct);

	
}

bool AFootballPlayer::IsFrontOfMeToGoalNet(FVector Target, float threshold)
{
	const FVector MyLocation = GetActorLocation();
	if( TargetGoalNet == nullptr) return false;
	const float ToGoalXDirection = TargetGoalNet->GetActorLocation().Y - MyLocation.Y;
	if (ToGoalXDirection > 0) {
		return Target.Y >= MyLocation.Y + threshold;
	} else {
		return Target.Y <= MyLocation.Y - threshold;
	}
}

bool AFootballPlayer::IsFrontOfTarget(AFootballPlayer* Target)
{
	FVector TargetToPlayer = GetActorLocation() - Target->GetActorLocation();
	TargetToPlayer.Normalize(0.001f);
	float angle = FVector::DotProduct(Target->GetActorForwardVector(), TargetToPlayer);
	angle = FMath::RadiansToDegrees(acosf(angle));

	//UE_LOG(LogTemp, Warning, TEXT("Angle: %f"), angle);
	if( angle > 0 && angle < 40) return true;
	return false;
	
}

bool AFootballPlayer::IsAttacker()
{
	return (Position == EPositions::ST_R
		|| Position == EPositions::ST_L
		|| Position == EPositions::ST
		|| Position == EPositions::LW
		|| Position == EPositions::RW);
	
}

bool AFootballPlayer::IsMiddler()
{
	return (Position == EPositions::AMF_L
		|| Position == EPositions::AMF_R
		|| Position == EPositions::AMF
		|| Position == EPositions::LMF
		|| Position == EPositions::RMF
		|| Position == EPositions::CM_R
		|| Position == EPositions::CM_L
		|| Position == EPositions::CM);
}

bool AFootballPlayer::IsDefender()
{
	return (Position == EPositions::RB
		|| Position == EPositions::LB
		|| Position == EPositions::CB
		|| Position == EPositions::CB_L
		|| Position == EPositions::CB_R
		|| Position == EPositions::DMF
		|| Position == EPositions::DMF_L
		|| Position == EPositions::DMF_R);
}

TArray<AFootballPlayer*> AFootballPlayer::GetTeammatesInMyArea(bool FromCurrentLocation)
{
	FVector SearchLocation = StartLocation;
	if( FromCurrentLocation )
	{
		SearchLocation = GetActorLocation();
	}

	TArray<AFootballPlayer*> SearchedPlayers;
	for (auto Player : Team->Players)
	{
		if(Player == this) continue;
		float DistanceToPlayer = FVector::Distance(SearchLocation, Player->GetActorLocation());
		if( DistanceToPlayer < RADIOUS_AREA)
		{
			SearchedPlayers.Add(Player);
		}
	}
	return SearchedPlayers;
}

TArray<AFootballPlayer*> AFootballPlayer::GetOpponentsInMyArea(bool FromCurrentLocation)
{
	FVector SearchLocation = StartLocation;
	if( FromCurrentLocation )
	{
		SearchLocation = GetActorLocation();
	}

	TArray<AFootballPlayer*> SearchedPlayers;
	for (auto Player : Team->OpponentTeam->Players)
	{
		if(Player == this) continue;
		float DistanceToPlayer = FVector::Distance(SearchLocation, Player->GetActorLocation());
		if( DistanceToPlayer < RADIOUS_AREA)
		{
			SearchedPlayers.Add(Player);
		}
	}
	return SearchedPlayers;
}

TArray<AFootballPlayer*> AFootballPlayer::GetBestTeammatesToPass()
{
	TArray<AFootballPlayer*> TargetPlayersToPass;
	for (auto Player : Team->Players)
	{
		if( Player == this) continue;

		if( FVector::Distance(Player->GetActorLocation(), GetActorLocation()) < DISTANCE_TO_PASS)
		{
			TargetPlayersToPass.Add(Player);
		}
		// if( IsFrontOfMe(Player->GetActorLocation()))
		// {
		// 	TargetPlayersToPass.Add(Player);
		// }
	}

	return TargetPlayersToPass;
}

bool AFootballPlayer::IsReachedToTarget(FVector TargetLocation)
{
	float DistanceToTarget = FVector::Distance(GetActorLocation(), TargetLocation);
	if( DistanceToTarget < DISTANCE_TO_REACH) return true;
	return false;
}

void AFootballPlayer::BallPassedToMe()
{
	WaitForBall = true;
	BallPassedStartTime = CurrentTime;
	UE_LOG(LogTemp, Warning, TEXT("Ball passed time %f"), BallPassedStartTime);
}

void AFootballPlayer::UpdateActionStartTime(EActs act)
{
	if( act == EActs::Tackling)
	{
		TackleActionStartTime = CurrentTime;
		UE_LOG(LogTemp, Warning, TEXT("Tackle started: %f"), TackleActionStartTime);
	}
	else if(act == EActs::PassAndRun || act == EActs::Shoot)
	{
		BallHitActionStartTime = CurrentTime;
	}
	else if(act == EActs::Crossing)
	{
		CrossActionStartTime = CurrentTime;
	}
	else if( act == EActs::Stunned)
	{
		StruggleActionStartTime = CurrentTime;
	}
}

void AFootballPlayer::BehaviorTacticPositioning()
{
	if ( IsHoldingBall ) return;
	//if ( CanControl ) return;
	if( IsReachedToTarget(TargetMoveLocation))
	{
		TargetMoveLocation = FindTargetLocation(false);
	}
	else
	{
		LookTo(TargetMoveLocation);
		Move(0,1);
	}
}

void AFootballPlayer::BehaviorRunForwardWithBall()
{
	if ( IsHoldingBall == false) return;
	
	if( IsReachedToTarget(TargetMoveLocation))
	{
		if( FMath::RandRange(0,10) < 5)
		{
			IsRunningForwardWithBall = false;
			//TargetMoveLocation = FindTargetLocation(true);
		}else
		{
			IsRunningForwardWithBall = false;
		}
	}
	else
	{
		IsRunningForwardWithBall = true;
		LookTo(TargetMoveLocation);
		Move(0,1);
	}	
}

void AFootballPlayer::BehaviorRunBehindDefenseLine()
{ 
	
}

void AFootballPlayer::BehaviorDefense()
{
	if( IsHoldingBall ) return;
	if(Ball->HolderPlayer == nullptr) return;
	if( CurrentAct == EActs::None)
	{
		if(Ball->HolderPlayer->Team == Team) return;
		
		float DistanceToBall = FVector::Distance(GetActorLocation(), Ball->GetActorLocation());
		if( DistanceToBall < DISTANCE_TO_TACKLE  && IsFrontOfTarget(Ball->HolderPlayer))
		{
			UE_LOG(LogTemp, Warning, TEXT("Tackle Start"));
			Tackle();
		}
	}
}

void AFootballPlayer::BehaviorAttack()
{
	
}

void AFootballPlayer::BehaviorPass()
{
	if( IsRunningForwardWithBall ) return;
	if( CurrentAct == EActs::None)
	{
		if( IsHoldingBall == false) return;
		TArray<AFootballPlayer*> BestPlayers = GetBestTeammatesToPass();
		if( BestPlayers.Num() > 0)
		{
			PassToPlayer(BestPlayers[FMath::RandRange(0, BestPlayers.Num()-1)]);
		}
	}
}

void AFootballPlayer::BehaviorShoot()
{
	if( CurrentAct == EActs::None)
	{
		if( IsHoldingBall == false) return;
		Shoot();
	}
}

void AFootballPlayer::ChaseBall()
{
	if( CurrentAct == EActs::None)
	{
		if( IsHoldingBall) return;
		//TargetMoveLocation = Ball->GetActorLocation() + Ball->SpherePhysics
		LookTo(Ball->GetActorLocation());
		Move(0,1);
	}
}

void AFootballPlayer::CheckEnvironment()
{
	
}

void AFootballPlayer::UpdateStatus()
{
	PlayerSelectedMark->SetVisibility(CanControl);
	PlayerDirectionArrow->SetVisibility(CanControl);
	if( GoalNet )
	{
		PlayerFieldProgress = FMath::Abs(GetActorLocation().Y - GoalNet->GetActorLocation().Y) / 12000.f;
	}
	IsDefending = false;	
	if( CurrentAct == EActs::Stunned)
	{
		ReleaseBall();
		return;
	}
	
	if( Ball && IsHoldingBall)
	{
		Ball->SetActorLocation(BallHoldComponent->GetComponentLocation());
	}
	
	if( Ball->HolderPlayer != nullptr && Ball->HolderPlayer->Team != Team)
	{
		if(	FVector::Distance(GetActorLocation(), Ball->GetActorLocation()) < DISTANCE_TO_DEFENSE
			&& IsFrontOfMeToGoalNet(Ball->GetActorLocation()) )
		{
			IsDefending = true;
		}
	}
}

void AFootballPlayer::UpdateSkillMove()
{
	if( IsDashing )
	{
		Animator->PlayRate = 1.5f;
		Move(0, 1);
	}else
	{
		Animator->PlayRate = 1.0f;
	}
	
	if( IsTackling || IsCrossing )
	{
		Move(0, 1);
	}
}

void AFootballPlayer::ApplyBehavior() // called from animation blueprint, anim notify
{
	
	if( CurrentAct == EActs::Shoot)
	{
		FVector BallLocation = Ball->GetActorLocation();
		FVector TargetLocation = Team->TargetGoalNet->GetRandomGoalTarget();
		FVector Direction = TargetLocation - BallLocation;
		LookTo(TargetLocation);
		
		UE_LOG(LogTemp, Warning, TEXT("Sending Hit Ball to Ball"));
		
		HitBall(Direction, 1.5f);

		GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &AFootballPlayer::FinishActionBallHit, 2, false);
	}
	else if( CurrentAct == EActs::PassAndRun)
	{
		LookTo(BallTargetLocation);
		
		FVector BallLocation = Ball->GetActorLocation();
		
		//DRAW_VECTOR(BallLocation, BallTargetLocation);
		
		FVector Direction = BallTargetLocation - BallLocation;
		
		HitBall(Direction, 1.4f);
		UE_LOG(LogTemp, Warning, TEXT("PassAndRun"));

		GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &AFootballPlayer::FinishActionBallHit, 2, false);
	}
	else if( CurrentAct == EActs::Tackling)
	{
		float DistanceToBall = FVector::Distance(GetActorLocation(), Ball->GetActorLocation());
		if( DistanceToBall < DISTANCE_TO_PICK_BALL)
		{
			TryToGrabBall();
		}
		
		GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &AFootballPlayer::FinishActionTackle, 2, false);
	}
	else if( CurrentAct == EActs::Stunned)
	{
		
	}
		
}

void AFootballPlayer::FinishAllActions()
{
	CurrentAct = EActs::None;
	DashEnd();
	IsCrossing = false;
	IsTackling = false;
}

void AFootballPlayer::FinishActionBallHit()
{
	if( CurrentAct == EActs::Shoot || CurrentAct == EActs::PassAndRun)
	{
		CurrentAct = EActs::None;
		DashEnd();
		IsCrossing = false;
		EnableColliders();
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong Ball Hit, Finished"));
	}
	
}

void AFootballPlayer::FinishActionStruggle()
{
	if( CurrentAct != EActs::Stunned)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong Struggle, Finished"));
	}
	CurrentAct = EActs::None;
	IsCrossing = false;
	DashEnd();
	StruggleActionStartTime = -1;
	
}

void AFootballPlayer::FinishActionCheerOrSad()
{
	if( CurrentAct == EActs::Sad || CurrentAct == EActs::Cheer)
	{
		CurrentAct = EActs::None;
		DashEnd();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong Cheer, Sad: Finished"));
	}
}

void AFootballPlayer::FinishActionTackle()
{
	if( CurrentAct != EActs::Tackling)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong Tackling, Finished"));
	}
	CurrentAct = EActs::None;
	IsTackling = false;
	DashEnd();
	TackleActionStartTime = -1;
	UE_LOG(LogTemp, Warning, TEXT("Tackle ended: %f"), CurrentTime);
}

void AFootballPlayer::FinishActionCross()
{
	if( CurrentAct != EActs::Crossing)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong Tackling, Finished"));
	}
	CurrentAct = EActs::None;
	IsCrossing = false;
	DashEnd();
	CrossActionStartTime = -1;
	UE_LOG(LogTemp, Warning, TEXT("Cross ended: %f"), CurrentTime);
}


void AFootballPlayer::Move(float ScaleRight, float ScaleForward)
{
	
	FVector const ForwardDirection = GetActorForwardVector();
	FVector const RightDirection = GetActorRightVector();
	AddMovementInput(ForwardDirection, ScaleForward);
	AddMovementInput(RightDirection, ScaleRight);
	
}

void AFootballPlayer::Rotate(float X, float Y)
{

	FVector TargetLoc(X, Y, 0);
	FRotator ToRot = UKismetMathLibrary::FindLookAtRotation(FVector::ZeroVector, TargetLoc);
	FRotator NewRot = FMath::RInterpTo(RootComponent->GetComponentRotation(), ToRot, 0.1f, 0.7f);
	SetActorRotation(NewRot);

}

void AFootballPlayer::MoveDirection(float X, float Y)
{
	if( CurrentAct == EActs::Stunned) return;
	FVector TargetLoc(X, Y, 0);
	Rotate(X, Y);
	Move(0,TargetLoc.Length());
}

FVector AFootballPlayer::FindTargetLocation(bool FromCurrentLocation)
{
	FVector PlayerForward = GetActorForwardVector();
	FVector TeamForward = Team->OpponentTeam->GoalNet->GetActorLocation() - Team->GoalNet->GetActorLocation();
	TeamForward.Normalize(0.001f);
	
	PlayerForward *= FMath::RandRange(RADIOUS_AREA/2.0f, RADIOUS_AREA);
	TeamForward *= FMath::RandRange(RADIOUS_AREA/2.0f, RADIOUS_AREA);
	
	float XX = FMath::RandRange(-45, 45);
	const FRotator rot(0,XX, 0);
	FVector Dir = rot.RotateVector(PlayerForward);
	FVector TeamDir = rot.RotateVector(TeamForward);
	
	TargetMoveLocation = GetActorLocation() + Dir;

	if( FromCurrentLocation == false)
	{
		TargetMoveLocation = StartLocation + TeamDir;
	}

	
	
	if(auto* const cont = GetController())
	{
		if( auto* const player = cont->GetPawn())
		{
			// obtain player location to use as an origin
			auto const Origin = GetActorLocation();

			// get the navigation system and generate a rondom location
			if( auto* const NavSys = UNavigationSystemV1::GetCurrent((GetWorld())))
			{
				FNavLocation Loc;
				if( NavSys->GetRandomReachablePointInRadius(Origin, SearchRadius, Loc))
				{
					return Loc.Location;
				}
			}
		}
	}
	return FVector::ZeroVector;
}

void AFootballPlayer::ReleaseBall()
{
	IsHoldingBall=false;
	GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &AFootballPlayer::EnableColliders, 2, false);
	
}

void AFootballPlayer::HoldBall()
{
	if( IsHoldingBall == false)
	{
		IsHoldingBall = true;
		Animator->PlayBallStopMontage();
		DisableColliders();
		//Team->SwitchPlayer();
	}
	
}

void AFootballPlayer::DisableColliders()
{
	RightFootCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftLegCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightLegCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BodyCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AFootballPlayer::EnableColliders()
{
	RightFootCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	LeftLegCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RightLegCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BodyCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AFootballPlayer::Shoot()
{
	if (!IsHoldingBall) {
		return;
	}
	if( Team->TargetGoalNet )
	{
		DashEnd();
		UE_LOG(LogTemp, Warning, TEXT("Shoot"));

		DisableColliders();
		Animator->PlayShootMontage();

		CurrentAct = EActs::Shoot;

	}
	
}

void AFootballPlayer::PassToTarget( FVector TargetPosition)
{
	if (!IsHoldingBall) {
		return;
	}

	BallTargetLocation = TargetPosition;
	
	UE_LOG(LogTemp, Warning, TEXT("Pass To Target"));

	DisableColliders();
	
	LookTo(BallTargetLocation);
	
	Animator->PlayPassMontage();

	DashEnd();
	CurrentAct = EActs::PassAndRun;

}

void AFootballPlayer::PassToPlayer(AFootballPlayer* TargetPlayer)
{
	if( !IsHoldingBall) return;
	DashEnd();
	UE_LOG(LogTemp, Warning, TEXT("Pass To Player"));
	TargetPlayer->BallPassedToMe();
	PassToTarget(TargetPlayer->GetActorLocation());

}

void AFootballPlayer::Cross()
{
	if (IsHoldingBall)
	{
		DashEnd();
		CurrentAct = EActs::Crossing;
		IsCrossing = true;
		GetCharacterMovement()->MaxWalkSpeed = MAX_RUN_SPEED;
		Animator->PlayCrossMontage(true);

		//GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &AFootballPlayer::FinishBehavior, 1, false);
	}
}

void AFootballPlayer::Tackle()
{
	if (!IsHoldingBall)
	{
		if( IsTackling ) return;
		
		CurrentAct = EActs::Tackling;
		IsTackling = true;

		UpdateActionStartTime(CurrentAct);
		
		float ActionTimeDuration = 1;
		if( FMath::RandRange(0, 10) < 5)
		{
			Animator->PlayTackleMontage(false);
			ActionTimeDuration = 1;
		}
		else
		{
			Animator->PlayTackleMontage(true);
			ActionTimeDuration = 3;
		}

		DashEnd();
	}
}

void AFootballPlayer::Dash()
{
	if( !IsDashing )
	{
		UE_LOG(LogTemp, Warning, TEXT("Dashing"));
		IsDashing = true;
		GetCharacterMovement()->MaxWalkSpeed = MAX_RUN_SPEED;
	}
}

void AFootballPlayer::DashEnd()
{
	IsDashing = false;
	GetCharacterMovement()->MaxWalkSpeed = NORMAL_RUN_SPEED;
}

void AFootballPlayer::Cheers()
{
	CurrentAct = EActs::Cheer;
	Animator->PlayCheerMontage();

}

void AFootballPlayer::Sad()
{
	CurrentAct = EActs::Sad;
	Animator->PlaySadMontage();

}

void AFootballPlayer::HitBall(FVector Direction, float Power)
{
	//UE_LOG(LogTemp, Warning, TEXT("HitBall"));
	float TPower = Direction.Length();
	UE_LOG(LogTemp, Warning, TEXT("HitBall: Distance %f"), TPower);
	Direction.Normalize(0.001f);

	TPower = FMath::Clamp(TPower, 700, 6000);
	FVector Velocity = FVector(Direction.X, Direction.Y, Direction.Z) * TPower * Power;
		
	Ball->Release();
	Ball->BallHit(this, Velocity);
}

void AFootballPlayer::TryToGrabBall()
{
	if( CurrentAct == EActs::Stunned || IsHoldingBall) return;
	if( CurrentAct == EActs::Shoot || CurrentAct == EActs::PassAndRun)
	{
		return;
	}
	
	float DistanceToBall = FVector::Distance(Ball->GetActorLocation(), GetActorLocation());
	if( DistanceToBall > DISTANCE_TO_PICK_BALL) return;
	
	if( Ball->HolderPlayer == nullptr)
	{
		Ball->Hold(this);
		return;
	}
	if( Ball->HolderPlayer->Team == Team)
	{
		return;
	}
	
	LookTo(Ball->GetActorLocation());
	
	bool CanCatchBall = true;
	if( Ball->HolderPlayer->IsCrossing)
	{
		CanCatchBall = (FMath::RandRange(1, 10) < 5);
	}
	if( CanCatchBall )
	{
		UE_LOG(LogTemp, Warning, TEXT("GotBall from TryToGrabBall"));
		Ball->HolderPlayer->Struggle();
		Ball->Hold(this);
		
	}
	
}


// Called every frame

void AFootballPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return;
	}
	CurrentTime = FPlatformTime::Seconds() - MatchStartTime;

	if( StruggleActionStartTime >= 0 && CurrentTime - StruggleActionStartTime > 2 )
	{
		if( CurrentAct == EActs::Stunned)
		{
			FinishActionStruggle();
		}
	}

	if( TackleActionStartTime >= 0 && CurrentTime - TackleActionStartTime > 2)
	{
		if( CurrentAct == EActs::Tackling)
		{
			FinishActionTackle();
		}
	}

	if( CrossActionStartTime >= 0 && CurrentTime - CrossActionStartTime > 2)
	{
		if( CurrentAct == EActs::Crossing)
		{
			FinishActionCross();
		}
	}

	if( BallPassedStartTime >= 0 && CurrentTime - BallPassedStartTime > 2)
	{
		BallPassedStartTime = -1;
		WaitForBall = false;
		UE_LOG(LogTemp, Warning, TEXT("Wait For ball false"));
	}
	
	if( WaitForBall ) return;
	
	UpdateStatus();

	TryToGrabBall();
	
	UpdateSkillMove();

	if( CurrentAct == EActs::Stunned) return;
	
	BehaviorDefense();
	
	//BehaviorTacticPositioning();

	BehaviorRunForwardWithBall();
	
	BehaviorPass();

	//BehaviorShoot();

	//ChaseBall();
}
