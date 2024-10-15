// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FootballTeam.h"

#include "HasTeam.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UHasTeam : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API IHasTeam
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
		/** Please add a function description */
	virtual const EFootballTeam GetTeam();

	
};
