// Fill out your copyright notice in the Description page of Project Settings.


#include "PassTarget.h"

FPassTarget::~FPassTarget()
{
}

FPassTarget::FPassTarget()
{
}

FPassTarget::FPassTarget(EPassType PathType, FString OptionName, AFootballPlayer* ActualTarget, FVector Position,
                         float PassPower)
{
	_PassType = PathType;
	_OptionName = OptionName;
	_ActualTarget = ActualTarget;
	_Position = Position;
	_PassPower = PassPower;
}
