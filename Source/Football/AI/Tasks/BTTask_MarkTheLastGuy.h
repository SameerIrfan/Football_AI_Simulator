// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MarkTheLastGuy.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_MarkTheLastGuy : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_MarkTheLastGuy(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	const float TO_GOAL_NET_FACTOR = 5.f;

	const float MIN_BALL_PROGRESS = .5f;
};
