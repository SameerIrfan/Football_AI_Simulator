// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOOTBALL_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Strength         = 50;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Acceleration     = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int TopSpeed         = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int DribbleSpeed     = 50;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Jump             = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Tackling         = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int BallKeeping      = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Passing          = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int LongBall         = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Agility          = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Shooting         = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int ShootPower       = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Positioning      = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int Reaction         = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	int BallControl      = 50;
		
};
