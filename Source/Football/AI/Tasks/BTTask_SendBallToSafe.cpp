// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SendBallToSafe.h"

#include "Football/DebugMacros.h"
#include "Football/Core/MatchManager.h"
#include "Football/Players/FootballPlayer.h"
#include "Football/Teams/Team.h"
#include "Misc/TextFilterExpressionEvaluator.h"

UBTTask_SendBallToSafe::UBTTask_SendBallToSafe(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Send Ball To Safe";
}

EBTNodeResult::Type UBTTask_SendBallToSafe::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	
	// if( Player->Team->BallProgress > maxBallProgress)
	// {
	// 	return EBTNodeResult::Succeeded;
	// }
	FVector Forward = Player->GetActorForwardVector();
	FRotator Rotate = FRotator(0, FMath::RandRange(ANGLE_MIN, ANGLE_MAX),0);
	
	FVector TargetSendAwayPosition = Player->GetActorLocation() + Rotate.RotateVector(Forward)*1000 ;

	Player->LookTo(TargetSendAwayPosition);
	Player->PassToTarget(TargetSendAwayPosition);

	UE_LOG(LogTemp, Warning, TEXT("PassToSafe"));
	DRAW_VECTOR(Player->GetActorLocation(), TargetSendAwayPosition);
	return EBTNodeResult::Succeeded;
	
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
}
