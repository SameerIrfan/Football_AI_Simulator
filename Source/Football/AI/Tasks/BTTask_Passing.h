// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Passing.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_Passing : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_Passing(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Passing", meta=(AllowPrivateAccess = "true"))
	bool OnlyIfFrontOfUs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Passing", meta=(AllowPrivateAccess = "true"))
	float MinBallProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Passing", meta=(AllowPrivateAccess = "true"))
	float MaxBallProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Passing", meta=(AllowPrivateAccess = "true"))
	float FrontXThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Passing", meta=(AllowPrivateAccess = "true"))
	bool OnlyIfCloserToGoalNet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Passing", meta=(AllowPrivateAccess = "true"))
	float MaxPassDistance;
};
