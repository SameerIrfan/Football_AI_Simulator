// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CanStealBall.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCanStealBall : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ICanBeStolenFrom;
class FOOTBALL_SIM_API ICanStealBall
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Football Sim | Stealing")
	void StartStealFrom(const TScriptInterface<ICanBeStolenFrom>& defender, const TScriptInterface<IBall>& ball);
	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Football Sim | Stealing")
	void GetStealingDistance(double& distance);

};
