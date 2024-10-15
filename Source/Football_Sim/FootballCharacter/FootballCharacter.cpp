// Fill out your copyright notice in the Description page of Project Settings.


#include "FootballCharacter.h"

#include "Components/SphereComponent.h"
#include "Football_Sim/Team/FootballTeam.h"


// Sets default values
AFootballCharacter::AFootballCharacter(): Team(EFootballTeam::HOME), StealingDistance(120), TackleBallTakingDistance(100), OwningDistance(90),
                                          WanderingRadius(300),
                                          WanderingOriginFromStartLocation(true
                                          	),
                                          IsTackling(false),
                                          DefaultMaxMovementSpeed(600), MaxMovementSpeedWithBall(500),
                                          HasBall(false)
{
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("WanderingRadiusDisplay"));
	
}

void AFootballCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFootballCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

