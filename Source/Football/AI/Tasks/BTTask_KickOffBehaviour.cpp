// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_KickOffBehaviour.h"

#include "Football/Core/MatchManager.h"

UBTTask_KickOffBehaviour::UBTTask_KickOffBehaviour(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Kick Off Behaviour";
}

EBTNodeResult::Type UBTTask_KickOffBehaviour::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
