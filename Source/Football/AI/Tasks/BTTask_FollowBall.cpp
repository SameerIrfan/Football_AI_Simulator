// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FollowBall.h"

UBTTask_FollowBall::UBTTask_FollowBall(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Follow Ball";
}

EBTNodeResult::Type UBTTask_FollowBall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
