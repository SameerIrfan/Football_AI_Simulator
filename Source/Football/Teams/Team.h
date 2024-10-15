// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football/Enum/AILevel.h"
#include "Football/Enum/Formations.h"
#include "Football/Enum/Positioins.h"
#include "Football/Enum/TacticTypes.h"
#include "Football/Enum/TeamBehaviour.h"
#include "Football/Enum/TeamType.h"
#include "GameFramework/Actor.h"
#include "Team.generated.h"

class AFootballPlayer;
class AGoalNet;
class ABallActor;
class AMatchManager;

UCLASS()
class FOOTBALL_API ATeam : public AActor
{
	GENERATED_BODY()
	
public:	
	ATeam();
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	FString TeamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	ETeamTypes TeamType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	EFormations Formation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	AMatchManager* MatchManager;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	TArray<AFootballPlayer*> Players;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	AFootballPlayer* ControllingPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	ATeam* OpponentTeam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	AGoalNet* GoalNet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	AGoalNet* TargetGoalNet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	ABallActor* Ball;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	ETacticTypes TacticType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess = "true"))
	ETeamBehaviour TeamBehaviour;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team", meta=(AllowPrivateAccess="true"))
	EAILevel AILevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Team", meta=(AllowPrivateAccess="true"))
	float BallProgress;

	
	UPROPERTY()
	AFootballPlayer* ClosedPlayerToBall;
	UPROPERTY()
	AFootballPlayer* ClosedPlayerToAttacker;
	
	FVector GetFieldPosition(EPositions PlayerPosition);
	AFootballPlayer* GetHolderPlayer();

	UFUNCTION(BlueprintCallable)
	void ControlPlayer(AFootballPlayer* Player);

	UFUNCTION(BlueprintCallable)
	AFootballPlayer* GetClosedPlayerToBall();

	UFUNCTION(BlueprintCallable)
	AFootballPlayer* GetClosedPlayerToAttacker();

	UFUNCTION(BlueprintCallable)
	AFootballPlayer* GetClosedTeammatesToPlayer(AFootballPlayer* Player);
	
	UFUNCTION(BlueprintCallable)
	AFootballPlayer* GetClosedPlayerToTarget(FVector TargetLocation);
	
	UFUNCTION(BlueprintCallable)
	void SwitchPlayer();
	// Interface Defender
	UFUNCTION(BlueprintCallable)
	void TackleProxy();
	
	UFUNCTION(BlueprintCallable)
	void SwitchProxy();
	
	UFUNCTION(BlueprintCallable)
	void DashAndPressProxy();
	
	UFUNCTION(BlueprintCallable)
	void DefenseProxy();

	// Interface Attacker
	UFUNCTION(BlueprintCallable)
	void SprintSkillProxy();

	UFUNCTION(BlueprintCallable)
	void ShootProxy();

	UFUNCTION(BlueprintCallable)
	void PassProxy();

	UFUNCTION(BlueprintCallable)
	void CrossProxy();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
private:	
	
};
