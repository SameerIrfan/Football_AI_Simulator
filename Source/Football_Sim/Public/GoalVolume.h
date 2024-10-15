// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "../Team/FootballTeam.h"
#include "../Team/HasTeam.h"
#include "GoalVolume.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_SIM_API AGoalVolume : public AVolume, public IHasTeam
{
	GENERATED_BODY()
	
	virtual const  EFootballTeam GetTeam() override;
	
	
};
