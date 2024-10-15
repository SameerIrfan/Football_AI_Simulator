// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "BallActor.generated.h"

class USphereComponent;
class ASoccerPlayer;
class AFootballPlayer;
class UCurveFloat;
class ATeam;

UCLASS()
class FOOTBALL_API ABallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABallActor();
	virtual void Tick(float DeltaTime) override;
	static ABallActor* GetWorldBall(UWorld* World);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	AFootballPlayer* HolderPlayer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	ATeam* HolderTeam = nullptr;

	FVector BallPosition(AFootballPlayer* player, float relaxation = 0);
	
	UFUNCTION(BlueprintCallable)
	void Hold(AFootballPlayer* basePlayer);

	UFUNCTION(BlueprintCallable)
	void Release();

	bool HolderBehave(FVector position, float deltaTime, float speedMod);

	void BallHit ( AFootballPlayer* hitter,  FVector velocity,	bool ignoreOffside = false);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	AFootballPlayer* LastTouchedPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	AFootballPlayer* LastHolder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	bool IsOnGoal;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	USphereComponent* BallCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SpherePhysics;

private:
	
	const float NETS_FACTOR_SPEED = 5;
	const float NETS_FACTOR_DISABLED_SPEED = 0.5f;

	const float IGNORE_COLLISION_TIME_FOR_BALL_HITTER = 1.0f;

	const float BALL_COLLIDE_DELAY = 0.25f;

	const float MAX_WORLD_POW = 200;

	const float MAX_VELOCTIY_POW = 200;

	
};
