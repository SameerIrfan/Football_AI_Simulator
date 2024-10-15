// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MatchSettings.h"
#include "Football/Enum/FoulType.h"
#include "Football/Enum/MatchStatus.h"
#include "Football/Enum/Positioins.h"
#include "Football/Enum/TeamType.h"
#include "Football/Enum/TeamBehaviour.h"
#include "GameFramework/Actor.h"
#include "MatchManager.generated.h"

class ABallActor;
class ATeam;
class AGoalNet;
class AFootballPlayer;
class UMatchSettings;

UCLASS()
class FOOTBALL_API AMatchManager : public AActor
{
	GENERATED_BODY()
	
public:	

	AMatchManager();
	virtual void Tick(float DeltaTime) override;

	static constexpr float FieldY = 12000.0f;
	static constexpr float FiledX = 9000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Match Status", meta=(AllowPrivateAccess="true"))
	UMatchSettings* MatchSettings;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Match Status", meta=(AllowPrivateAccess="true"))
	EMatchStatus MatchStatus = EMatchStatus::NotPlaying;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Match Status", meta=(AllowPrivateAccess="true"))
	TArray<ATeam*> Teams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Match Status", meta=(AllowPrivateAccess="true"))
	ATeam* UserTeam;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Match Status", meta=(AllowPrivateAccess="true"))
	TArray<AGoalNet*> GoalNets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Match Status", meta=(AllowPrivateAccess="true"))
	ABallActor* Ball;
	
	UFUNCTION(BlueprintCallable)
	static AMatchManager* GetMatchManager(UWorld* World);

	UFUNCTION(BlueprintCallable)
	AGoalNet* GetGoalNet(ETeamTypes TeamType);

	UFUNCTION(BlueprintCallable)
	ATeam* GetTeam(ETeamTypes TeamType); 

	UFUNCTION(BlueprintCallable)
	bool CanIMove(const ETeamBehaviour TeamBehaviour); 

	UFUNCTION(BlueprintCallable)
	void OnThrowIn(FVector Position);

	UFUNCTION(BlueprintCallable)
	void Corner(ETeamTypes Team);

	UFUNCTION(BlueprintCallable)
	void Foul(EFoulType FoulType, FVector Position, ATeam* Team, EPositions ExcludeKickerPosition);

	UFUNCTION(BlueprintCallable)
	void StartMatch();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	ETeamTypes WithTeamStarted = ETeamTypes::Home;
};
