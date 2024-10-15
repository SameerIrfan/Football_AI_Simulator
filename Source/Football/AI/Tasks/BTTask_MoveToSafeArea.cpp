// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToSafeArea.h"

UBTTask_MoveToSafeArea::UBTTask_MoveToSafeArea(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "MoveToSafeArea";
}

EBTNodeResult::Type UBTTask_MoveToSafeArea::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
