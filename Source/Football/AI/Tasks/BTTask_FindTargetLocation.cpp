// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindTargetLocation.h"

#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Football/AI/FootballAIController.h"
#include "Football/Players/FootballPlayer.h"

UBTTask_FindTargetLocation::UBTTask_FindTargetLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Random Location in NavMesh";
}

EBTNodeResult::Type UBTTask_FindTargetLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	FVector const TargetLocation = Player->FindTargetLocation();
	if( TargetLocation != FVector::ZeroVector)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), TargetLocation);
		// Finish with success
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
