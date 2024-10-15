// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GKPass.h"

UBTTask_GKPass::UBTTask_GKPass(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "GK Pass";
}

EBTNodeResult::Type UBTTask_GKPass::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
