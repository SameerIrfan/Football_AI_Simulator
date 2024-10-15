// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanStealBall.h"
#include "Football_Sim/Ball/Ball.h"
#include "UObject/Interface.h"
#include "CanBeStolenFrom.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCanBeStolenFrom : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API ICanBeStolenFrom
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Please add a function description */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Football Sim | Stealing")
	void BeStolenFrom(const TScriptInterface<ICanStealBall>& challenger, const TScriptInterface<IBall>& ball);

};
