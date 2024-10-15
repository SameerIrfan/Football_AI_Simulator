// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BaseBehaviour.h"

#include "Football/AI/FootballAIController.h"
#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/Players/FootballPlayer.h"


void UBTTask_BaseBehaviour::InitVariables(UBehaviorTreeComponent& OwnerComp)
{
	if(auto* const Cont = Cast<AFootballAIController>(OwnerComp.GetAIOwner()))
	{
		Player = Cast<AFootballPlayer>( Cont->GetPawn() );
	}
	Ball = ABallActor::GetWorldBall(GetWorld());
	MatchManager = AMatchManager::GetMatchManager(GetWorld());
}

bool UBTTask_BaseBehaviour::ShouldIAttackWhenNotHoldingTheBall()
{
	if (Ball->HolderPlayer == Player) {
		return false;
	}

	if (Ball->HolderPlayer != nullptr && Ball->HolderPlayer->Team != Player->Team) {
		return false;
	}

	if (Ball->HolderPlayer == nullptr && Ball->LastHolder != nullptr && Ball->LastHolder->Team != Player->Team) {
		return false;
	}

	return true;
}

bool UBTTask_BaseBehaviour::IsOurGoalKeeperHasTheBallWithProtection()
{
	return Ball->HolderPlayer != nullptr &&
				Ball->HolderPlayer->IsGk &&
				Ball->HolderPlayer->Team == Player->Team;
}

bool UBTTask_BaseBehaviour::IsOpponentGoalKeeperHasTheBallWithProtection()
{
	return Ball->HolderPlayer != nullptr &&
				Ball->HolderPlayer->IsGk &&
				Ball->HolderPlayer->Team != Player->Team;
}




