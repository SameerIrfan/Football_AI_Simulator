// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchManager.h"

#include "EngineUtils.h"
#include "Football/AI/Tasks/BTTask_BallChasing.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Ball/BallActor.h"
#include "Football/Teams/Team.h"

// Sets default values
AMatchManager::AMatchManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AMatchManager* AMatchManager::GetMatchManager(UWorld* World)
{
	/*TActorIterator<AMatchManager> ActorIterator{ World }*/;
	for (TActorIterator<AMatchManager> ActorIterator{ World }; ActorIterator; ++ActorIterator) {
		return *ActorIterator;
	}
	return nullptr;
}

AGoalNet* AMatchManager::GetGoalNet(ETeamTypes TeamType)
{
	for (auto Element : GoalNets)
	{
		if( Element->TeamType == TeamType)
		{
			return Element;
		}
	}
	return nullptr;
}

ATeam* AMatchManager::GetTeam(ETeamTypes TeamType)
{
	for (auto Element : Teams)
	{
		if(Element->TeamType == TeamType)
		{
			return Element;
		}
	}
	return nullptr;
}

bool AMatchManager::CanIMove(const ETeamBehaviour TeamBehaviour)
{
	if (MatchStatus != EMatchStatus::Playing) {
		return false;
	}

	switch (TeamBehaviour) {
		case ETeamBehaviour::OpponentThrowIn:
		case ETeamBehaviour::TeamThrowIn:
			return false;
	}

	return true;
}

void AMatchManager::OnThrowIn(FVector Position)
{
	
}

void AMatchManager::Corner(ETeamTypes Team)
{
}

void AMatchManager::Foul(EFoulType FoulType, FVector Position, ATeam* Team, EPositions ExcludeKickerPosition)
{
	MatchStatus = EMatchStatus::Freeze;
	if (FoulType == EFoulType::GoalKick) {
		//SetOutColliders(true);
	}
	//RefereeShortWhistleEvent
	//ResetOffsides();
	// WaitForMoment(1, runFunction);
	
}

void AMatchManager::StartMatch()
{
	for (auto GoalNet : GoalNets)
	{
		GoalNet->IsGoal = false;
	}
	MatchStatus = EMatchStatus::Playing;
}


// Called when the game starts or when spawned
void AMatchManager::BeginPlay()
{
	Super::BeginPlay();
	Ball = ABallActor::GetWorldBall(GetWorld());
}

// Called every frame
void AMatchManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

