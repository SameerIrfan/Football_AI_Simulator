// Fill out your copyright notice in the Description page of Project Settings.


#include "Team.h"

#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Players/FootballPlayer.h"

// Sets default values
ATeam::ATeam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FVector ATeam::GetFieldPosition(EPositions PlayerPosition)
{
	return FVector();
}

void ATeam::ControlPlayer(AFootballPlayer* Player)
{
	if( Player == nullptr) return;
	for (auto Element : Players)
	{
		Element->CanControl = false;
	}
	
	Player->CanControl = true;
	ControllingPlayer = Player;
}



AFootballPlayer* ATeam::GetHolderPlayer()
{
	for (auto Player : Players)
	{
		if( Player->IsHoldingBall)
		{
			return Player;
		}
	}
	return nullptr;
}

AFootballPlayer* ATeam::GetClosedPlayerToBall()
{
	float MinDistance = 10000000.f;
	FVector const BallLocation = Ball->GetActorLocation();

	for (auto const Player : Players)
	{
		if( Player->IsHoldingBall) return Player;
		
		FVector PlayerLocation = Player->GetActorLocation();
		float Distance = FVector::Distance(BallLocation, PlayerLocation);
		if( Distance < MinDistance )
		{
			MinDistance = Distance;
			ClosedPlayerToBall = Player;
		}
	}
	return ClosedPlayerToBall;
}

AFootballPlayer* ATeam::GetClosedPlayerToAttacker()
{
	float MinDistance = 10000000.f;

	AFootballPlayer* Attacker = OpponentTeam->GetHolderPlayer();
	
	if( Attacker != nullptr)
	{
		FVector AttackerLocation = Attacker->GetActorLocation();
		for (auto const Player : Players)
		{		
			FVector PlayerLocation = Player->GetActorLocation();
			float Distance = FVector::Distance(AttackerLocation, PlayerLocation);
			if( Distance < MinDistance )
			{
				MinDistance = Distance;
				ClosedPlayerToAttacker = Player;
			}
		}
		return ClosedPlayerToAttacker;
	}
	return nullptr;
}

AFootballPlayer* ATeam::GetClosedTeammatesToPlayer(AFootballPlayer* Player)
{
	AFootballPlayer* rPlayer = nullptr;
	float MinDistance = 100000000.f;
	
	FVector PLocation = Player->GetActorLocation();
	for (auto const tPlayer : Players)
	{
		if( tPlayer == Player) continue;
		FVector tPlayerLocation = tPlayer->GetActorLocation();
		float Distance = FVector::Distance(PLocation, tPlayerLocation);

		if( Distance < MinDistance )
		{
			MinDistance = Distance;
			rPlayer = tPlayer;
		}
	}
	return rPlayer;
}


AFootballPlayer* ATeam::GetClosedPlayerToTarget(FVector TargetLocation)
{
	AFootballPlayer* rPlayer = nullptr;
	float MinDistance = 100000000.f;
	
	for (auto const tPlayer : Players)
	{
		FVector tPlayerLocation = tPlayer->GetActorLocation();
		float Distance = FVector::Distance(TargetLocation, tPlayerLocation);

		if( Distance < MinDistance )
		{
			MinDistance = Distance;
			rPlayer = tPlayer;
		}
	}
	return rPlayer;
}

void ATeam::SwitchPlayer()
{
	AFootballPlayer * TPlayer = GetClosedPlayerToBall();
	if(TPlayer != nullptr)
	{
		ControlPlayer(TPlayer);
	}
}

// Defense Interface
void ATeam::TackleProxy()
{
	if( ControllingPlayer == nullptr) return;
	
}

void ATeam::SwitchProxy()
{
	if( ControllingPlayer == nullptr) return;
}

void ATeam::DashAndPressProxy()
{
	if( ControllingPlayer == nullptr) return;
}

void ATeam::DefenseProxy()
{
	if( ControllingPlayer == nullptr) return;
}


// Attacker Interface
void ATeam::SprintSkillProxy()
{
	if( ControllingPlayer == nullptr) return;
}

void ATeam::ShootProxy()
{
	if( ControllingPlayer == nullptr) return;
}

void ATeam::PassProxy()
{
	if( ControllingPlayer == nullptr) return;
}

void ATeam::CrossProxy()
{
	if( ControllingPlayer == nullptr) return;
}

// Called when the game starts or when spawned
void ATeam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if( MatchManager && Ball && GoalNet)
	{
		BallProgress = FMath::Abs(Ball->GetActorLocation().Y - GoalNet->GetActorLocation().Y)/AMatchManager::FieldY;
	}

	// if( MatchManager->MatchStatus == EMatchStatus::Playing)
	// {
	// 	if( GetHolderPlayer() != nullptr)
	// 	{
	// 		TeamBehaviour = ETeamBehaviour::Attacking;
	// 	
	// 	}else
	// 	{
	// 		if( OpponentTeam->GetHolderPlayer() != nullptr)
	// 		{
	// 			TeamBehaviour = ETeamBehaviour::Defending;
	// 		}
	// 		else
	// 		{
	// 			TeamBehaviour = ETeamBehaviour::BallChasing;
	// 		}
	// 	}
	// }

	
}  

