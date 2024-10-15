// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_RunBehindDefenseLine.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_RunBehindDefenseLine : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_RunBehindDefenseLine(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


private:
	const float MIN_DISTANCE_TO_HOLDER = 3000.f;
	const float MIN_DISTANCE_TO_OFFSIDELINE_TO_RUN = 500.f;
	const float MAX_DISTANCE_TO_OFFSIDELINE_TO_RUN = 1000.f;

	FVector RunDirection;
};
