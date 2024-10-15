// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Shooting.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_Shooting : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_Shooting(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shooting", meta=(AllowPrivateAccess = "true"))
	float minBallProgress;


	
};
