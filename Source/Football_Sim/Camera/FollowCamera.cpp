// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowCamera.h"

#include "Kismet/KismetMathLibrary.h"

void AFollowCamera::Tick(float DeltaTime)
{
    if (Target) {
        FVector targetPosition = Target->GetActorLocation();
        FVector MyLocation = GetActorLocation();
        if (IgnoreZ) {
            targetPosition.Z = MyLocation.Z;
        }
        this->SetActorLocation(targetPosition + Offset, false);

        
        FRotator ToRot = UKismetMathLibrary::FindLookAtRotation(MyLocation, targetPosition);
        FRotator NewRot = FMath::RInterpTo(RootComponent->GetComponentRotation(), ToRot, DeltaTime, 1);
        RootComponent->SetWorldRotation(ToRot);

        //UE_LOG(LogTemp, Warning, TEXT("Target"));
    }
}

void AFollowCamera::SetTarget(AActor* target)
{
	Target = target;
}
