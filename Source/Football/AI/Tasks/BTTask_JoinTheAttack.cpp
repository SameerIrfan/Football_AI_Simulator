// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_JoinTheAttack.h"

UBTTask_JoinTheAttack::UBTTask_JoinTheAttack(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Join The Attack";
}

EBTNodeResult::Type UBTTask_JoinTheAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
