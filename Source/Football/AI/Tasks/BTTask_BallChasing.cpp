// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BallChasing.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Football/Players/FootballPlayer.h"
#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/Teams/Team.h"

UBTTask_BallChasing::UBTTask_BallChasing()
{
	NodeName = "Ball Chasing";
}

EBTNodeResult::Type UBTTask_BallChasing::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	if ( MatchManager->MatchStatus != EMatchStatus::Playing)
	{
		return EBTNodeResult::Failed;
	}
	
	
	FVector BallLocation = Ball->GetActorLocation();

	AFootballPlayer* PlayerClosedToBall = Player->Team->GetClosedPlayerToBall();

	if( PlayerClosedToBall == Player)
	{
		// OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), BallLocation);
		UE_LOG(LogTemp, Warning, TEXT("Move to ball"));
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Ball);
		return Super::ExecuteTask(OwnerComp, NodeMemory);
	}
	return EBTNodeResult::Succeeded;
	
}


EBallChasingResult UBTTask_BallChasing::AmITheChaser()
{
	if( Ball->HolderPlayer == nullptr)
	{
		return EBallChasingResult::None; 
	}
	
	// if (!EnvironmentCheckForChasing()) {
	// 	UE_Log(this, $"Environment is not suitable for chasing.");
	// 	return false;
	// }
	//
	// if (IsTheBallGoingOutside ()) {
	// 	Log(this, $"Ball is going outside, no need for chasing.");
	// 	return false;
	// }

	FVector actualBallPos = Ball->GetActorLocation();
	bool lookPoint = actualBallPos.Y > FOCUS_TO_BALL_AFTER_HEIGHT;

	return  EBallChasingResult::None;
}

bool UBTTask_BallChasing::EnvironmentCheckForChasing()
{
	// TArray<AFootballPlayer*> OurTeamChasers;
	// for (auto TeamMate : Player->Team->Players)
	// {
	// 	
	// }
	return true;
}

float UBTTask_BallChasing::BallChasingDistance(AFootballPlayer* Target)
{
	return 0;
}
