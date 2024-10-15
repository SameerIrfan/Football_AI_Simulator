// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "PursuitScorable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UPursuitScorable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API IPursuitScorable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="FootballSim|Pursuit")
	float getCost() const;

};
