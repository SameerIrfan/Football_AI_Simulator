// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shooting.h"

#include "Football/Core/MatchManager.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Players/FootballPlayer.h"
#include "Football/Teams/Team.h"

UBTTask_Shooting::UBTTask_Shooting(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Shooting";
}

EBTNodeResult::Type UBTTask_Shooting::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);

	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	


	if (Player->Team->BallProgress < minBallProgress) {
		return EBTNodeResult::Succeeded;
	}

	FVector TargetLocation = Player->TargetGoalNet->GetRandomGoalTarget();
	FVector ShootingDir = TargetLocation - Player->GetActorLocation();

	Player->LookTo(TargetLocation);

	Player->Shoot();

	return EBTNodeResult::Succeeded;
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
