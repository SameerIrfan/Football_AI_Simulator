// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FootballPlayerAnim.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UFootballPlayerAnim : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API IFootballPlayerAnim
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Football Sim|Animations")
	void GetHasBall(bool& HasBall);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Football Sim|Animations")
	void GetCurrentSpeed(double& CurrentSpeed);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Football Sim|Animations")
	void GetMaxSpeed(double& MaxSpeed);

};
