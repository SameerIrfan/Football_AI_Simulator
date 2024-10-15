// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Passing.h"

#include "Football/DebugMacros.h"
#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/GoalNet/GoalNet.h"
#include "Football/Players/FootballPlayer.h"
#include "Football/Teams/Team.h"

UBTTask_Passing::UBTTask_Passing(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Passing";
}

EBTNodeResult::Type UBTTask_Passing::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);

	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Succeeded;
	}
	

	if( FMath::RandRange(0, 10) < 5)
	{
		return  EBTNodeResult::Succeeded;
	}
	// if (Player->Team->BallProgress < MinBallProgress) {
	// 	return EBTNodeResult::Succeeded;
	// }
	//
	// if (Player->Team->BallProgress > MaxBallProgress) {
	// 	return EBTNodeResult::Succeeded;
	// }

	FVector TargetGoalNetPosition = Player->TargetGoalNet->GetActorLocation();
	float DistanceToTargetGoalNet = FVector::Distance(Player->GetActorLocation(), TargetGoalNetPosition);

	TArray<AFootballPlayer*> Targets;
	for (AFootballPlayer* Target : Player->Team->Players)
	{
		// if( (!OnlyIfCloserToGoalNet || FVector::Distance (Target->GetActorLocation(), TargetGoalNetPosition) < DistanceToTargetGoalNet) &&
		// 			(!OnlyIfFrontOfUs || Player->IsFrontOfMe(Target->GetActorLocation(), FrontXThreshold)) )
		// {
		// 	Targets.Add(Target);
		// }
		if( Target == Player) continue;
		if( Target->IsGk) continue;
		if( FVector::Distance(Target->GetActorLocation(), Player->GetActorLocation()) < MaxPassDistance)
		{
			Targets.Add(Target);
		}
	}

	// FPassTarget Target = Player->FindPassTarget(Targets, TargetGoalNetPosition);
	// if( !Target.IsValid())
	// {
	// 	return EBTNodeResult::Succeeded;
	// }

	if( Targets.Num() <= 0)
	{
		return EBTNodeResult::Succeeded;
	}

	AFootballPlayer* Target = Targets[0];
	
	Player->LookTo(Target->GetActorLocation());
	
	
	FVector TargetDir = Target->GetActorForwardVector();
	TargetDir.Normalize(1.0f);
	FVector crossAddition = TargetDir * 200;

	DRAW_VECTOR(Player->GetActorLocation(), Target->GetActorLocation() + crossAddition);
	
	Player->PassToTarget(Target->GetActorLocation() + crossAddition);
	return EBTNodeResult::Succeeded;

	return EBTNodeResult::Failed;
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
}
