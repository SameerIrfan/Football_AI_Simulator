// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RunForwardWithBall.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Football/DebugMacros.h"
#include "Football/Core/MatchManager.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Players/FootballPlayer.h"
#include "Football/Teams/Team.h"

UBTTask_RunForwardWithBall::UBTTask_RunForwardWithBall(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Run Forward with Ball";
}

EBTNodeResult::Type UBTTask_RunForwardWithBall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);

	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	

	FVector PlayerLocation = Player->GetActorLocation();
	FVector TargetGoalNetLocation = Player->TargetGoalNet->GetActorLocation();
	FVector Direction = TargetGoalNetLocation - PlayerLocation;
	//Direction.Normalize(1.0f);
	
	FVector ToForward = Player->GoalNet->GetActorForwardVector();

	float lerp = FMath::RandRange(0.05f, 0.2f);

	
	FVector TargetDirection = FMath::Lerp(ToForward, Direction, lerp);

	FRotator Rotate = FRotator(0,FMath::RandRange(-30, 30), 0);

	//UE_LOG(LogTemp, Warning, TEXT("ROTATE%f"), Rotate.)
	
	FVector TargetLocation = PlayerLocation + Rotate.RotateVector(TargetDirection) ;

	//Player->LookTo(TargetLocation);
	Player->Move(0,100);
	//OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetMoveLocation"), TargetLocation);

	DRAW_VECTOR_SINGLE_FRAME(PlayerLocation, TargetLocation);
	
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
	
	return EBTNodeResult::Succeeded;
}
