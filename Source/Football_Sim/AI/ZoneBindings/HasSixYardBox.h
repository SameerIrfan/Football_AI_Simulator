// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HasSixYardBox.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UHasSixYardBox : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOOTBALL_SIM_API IHasSixYardBox
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Please add a function description */
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category="Football Sim|Zoning")
	void GetSixYardBoxOrigin(FVector& Origin);

	/** Please add a function description */
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category="Football Sim|Zoning")
	void GetSixYardBoxExtents(FVector& Extents);

};
