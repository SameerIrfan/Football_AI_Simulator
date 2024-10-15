// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FootballAIController.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_API AFootballAIController : public AAIController
{
	GENERATED_BODY()
public:
	explicit AFootballAIController(FObjectInitializer const& ObjectInitializer);

	void SetPlayerControlled(bool IsPlayerControlled);
	void SetActionStatus(bool IsPlayingAct);
protected:
	virtual void OnPossess(APawn* InPawn) override;
};
