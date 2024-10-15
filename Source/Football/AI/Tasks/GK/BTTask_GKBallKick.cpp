// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GKBallKick.h"

UBTTask_GKBallKick::UBTTask_GKBallKick(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "GK Ball Kick";
}

EBTNodeResult::Type UBTTask_GKBallKick::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
