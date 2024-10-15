// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football/Enum/TeamType.h"
#include "GameFramework/Actor.h"
#include "GoalNet.generated.h"

class USphereComponent;
class UBoxComponent;
class AMatchManager;
class ABallActor;

UCLASS()
class FOOTBALL_API AGoalNet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalNet();
	virtual void Tick(float DeltaTime) override;
	static AGoalNet* GetGoalNet(UWorld* World, const ETeamTypes MyTeamType);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GoalNet", meta=(AllowPrivateAccess="true"))
	ETeamTypes TeamType;
	
	UFUNCTION(BlueprintCallable)
	FVector GetRandomGoalTarget();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MatchManager Ref", meta=(AllowPrivateAccess="true"))
	AMatchManager* MatchManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ball Ref", meta=(AllowPrivateAccess="true"))
	ABallActor* Ball;
	
	UPROPERTY()
	bool IsGoal = false;

	UFUNCTION(BlueprintCallable)
	void GoalIn();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GoalNet", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GoalNet", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* GoalNetCollision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GoalNet", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> GoalTargets;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GoalNet", meta = (AllowPrivateAccess = "true"))
	TArray<UBoxComponent*> GoalNetOutCollisions;

	
private:	
	
};
