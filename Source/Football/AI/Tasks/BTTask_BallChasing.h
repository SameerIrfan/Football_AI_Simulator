// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BTTask_BallChasing.generated.h"

class AFootballPlayer;

enum EBallChasingResult {
	None,
	SecondaryChaser,
	ChaserTrue,
	/// <summary>
/// We are the chaser but one of our opponents are closer than us to chase.
/// </summary>
	ChaserTrueButCaution,
	/// <summary>
/// We know we will get the ball.
/// </summary>
};

UCLASS()
class FOOTBALL_API UBTTask_BallChasing : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()

public:
	float ChasingDistance;
	
	UBTTask_BallChasing();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	EBallChasingResult AmITheChaser();
	bool EnvironmentCheckForChasing ();
	static float BallChasingDistance (AFootballPlayer* Target);

private:
	const float MAX_CHASERS_DISTANCE_TOEACHOTHER = 1000;
	const float FOCUS_TO_BALL_AFTER_HEIGHT = 300.0f;
	const float MAX_BALL_HEIGHT_FOR_CAUTION = 30;

	const float MAX_PROGRESS_FOR_CAUTION = 50;

	const int LIMIT_CHASERS_BY_DISTANCE = 1000;
};
