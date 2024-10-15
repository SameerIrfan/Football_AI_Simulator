// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TryToTackle.h"

#include "Football/AI/FootballAIController.h"
#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/Players/FootballPlayer.h"

UBTTask_TryToTackle::UBTTask_TryToTackle(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Try To Tackle";
}

EBTNodeResult::Type UBTTask_TryToTackle::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);

	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	
	// Ball = ABall::GetWorldBall(GetWorld());
	// verify(Ball != nullptr);

	FVector BallLocation = Ball->GetActorLocation();
	float DistanceToHolderPlayer = FVector::Distance(BallLocation, Player->GetActorLocation());
	
	if( DistanceToHolderPlayer < FMath::RandRange(50, 100) )
	{
		
		return EBTNodeResult::Succeeded;
	
	}else
	{
		return EBTNodeResult::Succeeded;
	}
	
	
	//
	// if (Ball->HolderPlayer == nullptr || Ball->HolderPlayer->Team == Player->Team)
	// {
	// 	return EBTNodeResult::Failed;
	// }
	
}
