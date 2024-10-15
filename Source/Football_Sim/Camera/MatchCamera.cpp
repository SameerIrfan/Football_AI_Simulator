// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchCamera.h"

#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMatchCamera::AMatchCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMatchCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMatchCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Target) {
		FVector targetPosition = Target->GetActorLocation();
		FVector MyLocation = GetActorLocation();
		SetActorLocation(targetPosition + Offset, false);
		FRotator ToRot = UKismetMathLibrary::FindLookAtRotation(MyLocation, targetPosition);
		FRotator NewRot = FMath::RInterpTo(RootComponent->GetComponentRotation(), ToRot, DeltaTime, 0.3f);
		SetActorRotation(NewRot);
		//UE_LOG(LogTemp, Warning, TEXT("Target"));
	}
}

