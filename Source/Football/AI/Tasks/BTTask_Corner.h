// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Corner.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_Corner : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_Corner(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
