// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TacticalPositioning.h"

#include "Football/Core/MatchManager.h"

UBTTask_TacticalPositioning::UBTTask_TacticalPositioning(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Tactical Positioning";
}

EBTNodeResult::Type UBTTask_TacticalPositioning::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EMovementType UBTTask_TacticalPositioning::RequiredMovementType(FVector start, FVector end)
{
	float distance = FVector::Distance(start, end);

	if (distance > 400) {
		return EMovementType::BestHeCanDo;
	} else if (distance > 200) {
		return EMovementType::Normal;
	} else {
		return EMovementType::Relax;
	}
}
