// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Dribbling.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_Dribbling : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_Dribbling(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dribbling", meta=(AllowPrivateAccess="true"))
	float Chance;
};
