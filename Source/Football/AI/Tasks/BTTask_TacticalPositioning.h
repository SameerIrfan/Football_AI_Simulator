// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Football/Enum/MovementType.h"
#include "BTTask_TacticalPositioning.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_TacticalPositioning : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_TacticalPositioning(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	EMovementType RequiredMovementType(FVector start, FVector end);
};
