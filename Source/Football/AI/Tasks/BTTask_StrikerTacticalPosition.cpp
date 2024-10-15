// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StrikerTacticalPosition.h"

UBTTask_StrikerTacticalPosition::UBTTask_StrikerTacticalPosition(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Striker Tactical Position";
}

EBTNodeResult::Type UBTTask_StrikerTacticalPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
