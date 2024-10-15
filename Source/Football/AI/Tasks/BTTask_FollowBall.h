// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBehaviour.h"
#include "BTTask_FollowBall.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API UBTTask_FollowBall : public UBTTask_BaseBehaviour
{
	GENERATED_BODY()
public:
	explicit UBTTask_FollowBall(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
