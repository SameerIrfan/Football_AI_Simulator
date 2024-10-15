// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Dribbling.h"

#include "Football/Core/MatchManager.h"
#include "Football/Players/FootballPlayer.h"

UBTTask_Dribbling::UBTTask_Dribbling(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Dribbling";
}

EBTNodeResult::Type UBTTask_Dribbling::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);

	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	


	return EBTNodeResult::Succeeded;
}
