// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MatchSettings.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOOTBALL_API UMatchSettings : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMatchSettings();

	float PassHeight =  1;
	float CrossHeight =  1;
	float PositioningMistakeModifier = 0.1f; // range 0.1 to 1
	float PositioningMistakeUpdateInPerSeconds = 3; // range 0, 20
	float LongBallSkillActivationDistanceMin = 22;
	float LongBallSkillActivationDistanceMax = 35;
	float LongBallSkillPercentageAtDistance = 50 ;
	float StrengthModifier = 0.25f; // 0 ~ 0.25
	float AccelerationModifier = 0.05f;
	float TopSpeedModifier = 0.05f;
	float AgilityModifier = 1.0f;
	float ShootingModifier = 1.0f;
	float PassingModifier = 1.0f;
	float DribbleModifier = 1.0f;
	float AI_ShootTolerance = 25.0f;
	float Ball_MinHitVelocity = 5.0f;
	float Tackling_Difficulty = 2.0f;

	//Passing
	float PassingPlayerVelocityModifier = 0.25f;
	float PassingDistancePlayerVelocityModifier = 0.01f;
	float PassingBackwardMaxDistance = 20.0f;
	float PassingOptionPriorityPower = 5.0f;
	float PassingOptionDistanceToPriority = 0.1f;
	float PassingCrossPriority = 10.0f;
	float MinimumPassDistance = 3.0f;
	float PassingFieldBoundCheck = 5.0f;
	float PassingMiddlePriority = 0.2f;
	float XPowerPow = 1;
	float PassPowerCrossMod = 2.0f;

	//Shooting
	float ShootingForwardAxisMultiplier = 2.0f;
	float ShootingUpAxisDistanceMultiplier = 4.0f;
	float ShootingBlockAngle = 10.0;

	//PlayerSettings
	float MinimumDistanceToTeammates = 3.5f;

	//RunForwardBehaviour
	float RunForwardLerpSpeed = 1.0f;
	float RunForwardAngleLerpMod = 20.0f;

	float BestOptionToTargetGKAddition = -10;
	float BallChasingDistanceGKAddition = 1;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
