// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football/Enum/PassType.h"
#include "PassTarget.generated.h"
/**
 * 
 */
class AFootballPlayer;

USTRUCT(Blueprintable)
struct FOOTBALL_API FPassTarget
{
public:
	
	GENERATED_BODY()
	FPassTarget();
	FPassTarget(EPassType PathType, FString OptionName, AFootballPlayer* ActualTarget, FVector Position, float PassPower);
	~FPassTarget();

	EPassType _PassType;
	FString _OptionName;
	AFootballPlayer* _ActualTarget;
	FVector _Position;
	float _PassPower;

	bool IsValid()
	{
		return !_OptionName.IsEmpty(); 
	}
};
