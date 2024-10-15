// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Corner.h"

#include "Football/Core/MatchManager.h"

UBTTask_Corner::UBTTask_Corner(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Corner Behaviour";
}

EBTNodeResult::Type UBTTask_Corner::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
