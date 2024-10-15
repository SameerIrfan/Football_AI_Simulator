// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_RunForwardWithBall.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_RunForwardWithBall : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_RunForwardWithBall(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunForwardWithBall", meta=(AllowPrivateAccess="true"))
	float MinBallProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunForwardWithBall", meta=(AllowPrivateAccess="true"))
	float MaxBallProgress = 1;
};
