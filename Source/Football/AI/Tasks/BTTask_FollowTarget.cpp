// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FollowTarget.h"

UBTTask_FollowTarget::UBTTask_FollowTarget(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Follow Target";
}

EBTNodeResult::Type UBTTask_FollowTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
