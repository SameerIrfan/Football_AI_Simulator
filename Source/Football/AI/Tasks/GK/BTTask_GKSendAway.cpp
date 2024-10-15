// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GKSendAway.h"

UBTTask_GKSendAway::UBTTask_GKSendAway(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "GK Send Ball Away";
}

EBTNodeResult::Type UBTTask_GKSendAway::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
