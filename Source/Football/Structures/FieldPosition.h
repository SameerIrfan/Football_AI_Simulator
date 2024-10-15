// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football/Enum/Positioins.h"
#include "FieldPosition.generated.h"

USTRUCT(BlueprintType)
struct FOOTBALL_API FFieldPosition
{
public:
	GENERATED_BODY()

	EPositions Position;

	float HorizontalPlacement;

	float VerticalPlacement;
	
};
