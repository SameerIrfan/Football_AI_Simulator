// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FootballCharacter.generated.h"

class IBall;
class ICanBeStolenFrom;
enum class EFootballTeam : uint8;
class UTimelineComponent;
class USphereComponent;
UCLASS()
class FOOTBALL_SIM_API AFootballCharacter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFootballCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<USphereComponent> Sphere;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<USceneComponent> BallAnchor;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="BP_FootballPlayer_Base")
	TObjectPtr<UTimelineComponent> TacklingTimeline;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Team")
	EFootballTeam Team;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBallWasJustStolenFromMe, TScriptInterface<ICanStealBall>, challenger);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Football Sim | Stealing")
	FBallWasJustStolenFromMe BallWasJustStolenFromMe;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	double StealingDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	double TackleBallTakingDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	double OwningDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	double WanderingRadius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	FVector WanderingOrigin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	bool WanderingOriginFromStartLocation;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStealingComplete, TScriptInterface<ICanBeStolenFrom>, defender, TScriptInterface<IBall>, ball);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Football Sim |Stealing")
	FStealingComplete StealingComplete;


	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Football Sim")
	TObjectPtr<AActor> AttachedBallActor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Stealing|Debug")
	FVector SelfLocationBeforeTackle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Stealing")
	TObjectPtr<UAnimMontage> TackleMontage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Stealing|Debug")
	bool IsTackling;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	double DefaultMaxMovementSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	double MaxMovementSpeedWithBall;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Stealing|Debug")
	bool HasBall;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Stealing")
	TObjectPtr<UAnimMontage> BeTackledMontage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Football Sim|Character Settings")
	TObjectPtr<UAnimMontage> ShootMontage;
};
