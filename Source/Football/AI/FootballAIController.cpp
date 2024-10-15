// Fill out your copyright notice in the Description page of Project Settings.


#include "FootballAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Football/Players/FootballPlayer.h"

AFootballAIController::AFootballAIController(FObjectInitializer const& ObjectInitializer)
{

}

void AFootballAIController::SetPlayerControlled(bool IsPlayerControlled)
{
	GetBlackboardComponent()->SetValueAsBool(FName("IsPlayerControlled"), IsPlayerControlled);
}

void AFootballAIController::SetActionStatus(bool IsPlayingAct)
{
	GetBlackboardComponent()->SetValueAsBool(FName("IsPlayingAct"), IsPlayingAct);
}

void AFootballAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	
	if (AFootballPlayer* const player = Cast<AFootballPlayer>(InPawn))
	{
		// if (UBehaviorTree* const tree = player->GetBehaviorTree())
		// {
		// 	UBlackboardComponent* b;
		// 	UseBlackboard(tree->BlackboardAsset, b);
		// 	Blackboard = b;
		// 	RunBehaviorTree(tree);
		// }
	}
}
