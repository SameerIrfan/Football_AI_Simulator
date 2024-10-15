// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MarkTheLastGuy.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Football/Core/MatchManager.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Players/FootballPlayer.h"
#include "Football/Teams/Team.h"

UBTTask_MarkTheLastGuy::UBTTask_MarkTheLastGuy(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Mark The Last Guy";
}

EBTNodeResult::Type UBTTask_MarkTheLastGuy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	
	if( Player->Team->BallProgress < MIN_BALL_PROGRESS)
	{
		return EBTNodeResult::Failed;
	}

	

	AFootballPlayer* TargetPlayer = nullptr;
	TArray<AFootballPlayer*> OpponentPlayers = Player->Team->OpponentTeam->Players;
	float MaxPlayerFieldProgress = 0;
	for (const auto OpponentPlayer : OpponentPlayers)
	{
		if( OpponentPlayer->IsGk ) continue;
		if( OpponentPlayer->PlayerFieldProgress > MaxPlayerFieldProgress)
		{
			TargetPlayer = OpponentPlayer;
			MaxPlayerFieldProgress = OpponentPlayer->PlayerFieldProgress;
		}
	}

	if( TargetPlayer != nullptr )
	{
		Player->CurrentAct = EActs::MarkTheLastGuy;

		FVector targetPlayerPos = TargetPlayer->GetActorLocation();
		FVector TargetToGoalNet = Player->GoalNet->GetActorLocation() - targetPlayerPos;
		TargetToGoalNet.Normalize(1.0f);
		FVector target = targetPlayerPos + TargetToGoalNet * TO_GOAL_NET_FACTOR;

//		Player->FocusToBall();
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetMoveLocation"), target);
		
		return Super::ExecuteTask(OwnerComp, NodeMemory);
	}
	return EBTNodeResult::Failed;
}
