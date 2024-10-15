// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IsInOffside.h"

UBTTask_IsInOffside::UBTTask_IsInOffside(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Is In Offside";
}

EBTNodeResult::Type UBTTask_IsInOffside::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
