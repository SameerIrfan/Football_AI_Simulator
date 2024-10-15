// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BallOwnerTracker.generated.h"


class IBall;
class ICanStealBall;
class ICanBeStolenFrom;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FOOTBALL_SIM_API UBallOwnerTracker : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBallOwnerTracker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void NotifyPlayerReceiveBall(AActor* Player);
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void NotifyBallLeftPlayer(AActor* LastPlayer);
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void NotifyTackleOccurred(TScriptInterface<ICanBeStolenFrom> defender, TScriptInterface<ICanStealBall> challenger, TScriptInterface<IBall> ball);
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void NotifyPlayerShotBall(AController* Shooter);
	/** Please add a variable description */
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerReceivedBall, AActor*, NewPlayer);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")

	FPlayerReceivedBall PlayerReceivedBall;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<AActor> CurrentBallHolder;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<AActor> LastBallHolder;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerLeftBall, AActor*, LastPlayer);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FPlayerLeftBall PlayerLeftBall;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTackleOccured, TScriptInterface<ICanBeStolenFrom>, defender, TScriptInterface<ICanStealBall>, challenger, TScriptInterface<IBall>, ball);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FTackleOccured TackleOccured;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerShotBall, AController*, Shooter);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FPlayerShotBall PlayerShotBall;

};
