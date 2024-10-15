// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GKGoToPenaltyPoint.h"

UBTTask_GKGoToPenaltyPoint::UBTTask_GKGoToPenaltyPoint(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "GK Go To Penalty Point";
}

EBTNodeResult::Type UBTTask_GKGoToPenaltyPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
