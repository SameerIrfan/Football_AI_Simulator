// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Ball.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UBall : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API IBall
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnLeave();
	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnTake(UObject* Taker);
	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Shoot(FVector Target);

};
