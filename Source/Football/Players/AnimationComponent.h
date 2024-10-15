// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"

class AFootballPlayer;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOOTBALL_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AFootballPlayer* PlayerRef;
public:	
	// Sets default values for this component's properties
	UAnimationComponent();

	// *Montages 
	void PlayBallStopMontage();
	void PlayShootMontage();
	void PlayPassMontage();
	void PlayTackleMontage(bool IsSliding);
	void PlayCrossMontage(bool IsAttacking);
	void PlayCheerMontage();
	void PlaySadMontage();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* PassMontage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ShootMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* CrossMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* TackleMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* CheerMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* SadMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* BallStopMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* KickMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* BallThrowMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* BallLoseMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> BallStopMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> BallLoseMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> PassMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> ShootMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> KickMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> BallThrowMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> CrossMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> CheerMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> SadMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages Sections", meta = (AllowPrivateAccess = "true"))
	TArray<FName> TackleMontageSections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta = (AllowPrivateAccess = "true"))
	float PlayRate = 1.0f;
	
	void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName);
	int32 PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames);
	
};
