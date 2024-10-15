// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_DefenseTacticalPosition.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_DefenseTacticalPosition : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_DefenseTacticalPosition(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	const float OFFSIDE_LINE_Y_DIFF_BETWEEN_BALL = -2;

	const float KEEP_DIST_BETWEEN_BALL_ON_Y = 500;

	const float LEAK_CLOSER_0_1 = 0.5f;
};
