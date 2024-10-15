// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_TryToTackle.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_TryToTackle : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()

public:
	explicit UBTTask_TryToTackle(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	const float POSITIONING_MISTAKE_MOD = 0.05f;
	const float MAX_BALL_HEIGHT = 500;
private:
	
};
