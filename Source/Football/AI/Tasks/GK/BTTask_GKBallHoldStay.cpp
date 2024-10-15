// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GKBallHoldStay.h"

UBTTask_GKBallHoldStay::UBTTask_GKBallHoldStay(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "GK Ball Hold";
}

EBTNodeResult::Type UBTTask_GKBallHoldStay::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
