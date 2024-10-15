// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Crossing.h"

#include "Football/Core/MatchManager.h"
#include "Football/Players/FootballPlayer.h"

UBTTask_Crossing::UBTTask_Crossing(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Crossing";
}

EBTNodeResult::Type UBTTask_Crossing::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);

	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}


	return EBTNodeResult::Succeeded;
}
