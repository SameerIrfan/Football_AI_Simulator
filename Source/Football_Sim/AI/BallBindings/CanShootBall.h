// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CanShootBall.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCanShootBall : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API ICanShootBall
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Football Sim")
	void StartShootTowards(FVector TargetLocation);

	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Football Sim")
	void FinishShot();

};
