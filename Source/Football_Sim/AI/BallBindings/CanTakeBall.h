// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football_Sim/Ball/Ball.h"
#include "UObject/Interface.h"
#include "CanTakeBall.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCanTakeBall : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API ICanTakeBall
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TakeBall(const TScriptInterface<IBall>& Ball);

	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LeaveBall();

	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetBallOwningDistance(double& distance);

};
