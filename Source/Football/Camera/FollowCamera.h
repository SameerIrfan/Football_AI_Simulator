// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "FollowCamera.generated.h"

class AActor;
/**
 * 
 */
UCLASS()
class FOOTBALL_API AFollowCamera : public ACameraActor
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	void SetTarget(AActor* target);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool IgnoreZ;


};
