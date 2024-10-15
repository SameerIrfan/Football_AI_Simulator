// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football/AI/Tasks/BTTask_BaseBehaviour.h"
#include "BTTask_GKGoToPenaltyPoint.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_GKGoToPenaltyPoint : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_GKGoToPenaltyPoint(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
