// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ThrowIn.h"

#include "Football/Core/MatchManager.h"


UBTTask_ThrowIn::UBTTask_ThrowIn(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Throw In";
}

EBTNodeResult::Type UBTTask_ThrowIn::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
