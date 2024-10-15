// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RunBehindDefenseLine.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Football/Ball/BallActor.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Players/FootballPlayer.h"

UBTTask_RunBehindDefenseLine::UBTTask_RunBehindDefenseLine(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Run Behind Defense Line";
}

EBTNodeResult::Type UBTTask_RunBehindDefenseLine::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	Ball = ABallActor::GetWorldBall(GetWorld());
	
	if (Ball->HolderPlayer == nullptr || Ball->HolderPlayer == Player || Ball->HolderPlayer->Team != Player->Team)
	{
		return EBTNodeResult::Failed;
	}
	float distanceToHolder = FVector::Distance(Player->GetActorLocation(), Ball->HolderPlayer->GetActorLocation());

	if (distanceToHolder < MIN_DISTANCE_TO_HOLDER ) {

		RunDirection = (Player->TargetGoalNet->GetActorLocation() - Player->GetActorLocation());
		RunDirection.Normalize(1.0f);
		RunDirection = RunDirection * 500;
	} else {
		return EBTNodeResult::Failed;
	}

	FVector TargetLocation = Player->GetActorLocation() + RunDirection;
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetMoveLocation"), TargetLocation);
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
