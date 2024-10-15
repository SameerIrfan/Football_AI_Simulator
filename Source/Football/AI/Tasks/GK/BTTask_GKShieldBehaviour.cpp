// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GKShieldBehaviour.h"

UBTTask_GKShieldBehaviour::UBTTask_GKShieldBehaviour(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "GK Shield";
}

EBTNodeResult::Type UBTTask_GKShieldBehaviour::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
