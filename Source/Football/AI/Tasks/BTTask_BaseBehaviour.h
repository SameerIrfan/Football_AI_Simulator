// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "Football/Enum/MatchStatus.h"
#include "Football/Enum/TeamBehaviour.h"
#include "BTTask_BaseBehaviour.generated.h"

class AFootballPlayer;
class ABallActor;
class AGoalNet;
class AMatchManager;

UCLASS()
class FOOTBALL_API UBTTask_BaseBehaviour : public UBTTask_MoveTo
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess="true"))
	AFootballPlayer* Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess="true"))
	ABallActor* Ball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess="true"))
	AMatchManager* MatchManager;
	
	void InitVariables(UBehaviorTreeComponent& OwnerComp);

	const float ANGLE_MIN = -80;
	const float ANGLE_MAX = 80;
private:
	
protected:
	bool ShouldIAttackWhenNotHoldingTheBall();
	bool IsOurGoalKeeperHasTheBallWithProtection();
	bool IsOpponentGoalKeeperHasTheBallWithProtection();
};
