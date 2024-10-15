// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Football/Constants.h"
#include "Football/Enum/ActionStates.h"
#include "Football/Enum/Positioins.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Football/Enum/Acts.h"
#include "Football/Enum/TeamBehaviour.h"
#include "Football/Enum/TeamType.h"
#include "Football/Structures/PassTarget.h"
#include "GameFramework/Character.h"
#include "FootballPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;
class ABallActor;
class ATeam;
class AGoalNet;
class AMatchManager;
class UBoxComponent;
class UAttributeComponent;
class UAnimationComponent;
class UStatusComponent;
class UBehaviorComponent;

UCLASS()
class FOOTBALL_API AFootballPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AFootballPlayer();
	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void ReleaseBall();
	UFUNCTION()
	void HoldBall();

	UFUNCTION()
	void DisableColliders();
	UFUNCTION()
	void EnableColliders();
	
	UFUNCTION()
	FVector FindTargetLocation(bool FromCurrentLocation = false);

	UFUNCTION()
	bool IsFrontOfMeToGoalNet (FVector Target, float threshold = 0); 

	UFUNCTION()
	bool IsFrontOfTarget (AFootballPlayer* Target); 
	
	UFUNCTION()
	bool IsAttacker();

	UFUNCTION()
	bool IsMiddler();

	UFUNCTION()
	bool IsDefender();
	
	
	UFUNCTION(BlueprintCallable)
	void Move(float ScaleLeft, float ScaleForward);

	UFUNCTION(BlueprintCallable)
	void Rotate(float ScaleYaw, float ScalePitch);

	UFUNCTION(BlueprintCallable)
	void MoveDirection(float X, float Y);

	
	UFUNCTION()
	void LookTo(FVector TargetLocation);  
	
	UFUNCTION(BlueprintCallable)
	void Shoot();									

	UFUNCTION(BlueprintCallable)
	void PassToTarget (FVector targetPosition);		 

	UFUNCTION(BlueprintCallable)
	void PassToPlayer(AFootballPlayer *TargetPlayer);
	
	UFUNCTION(BlueprintCallable)
	void Cross();									

	UFUNCTION(BlueprintCallable)
	void Tackle();

	UFUNCTION(BlueprintCallable)
	void Dash();

	UFUNCTION(BlueprintCallable)
	void DashEnd();
	
	UFUNCTION(BlueprintCallable)
	void Cheers();

	UFUNCTION(BlueprintCallable)
	void Sad();
	
	UFUNCTION(BlueprintCallable)
	void Struggle ();
	
	UFUNCTION(BlueprintCallable)
	void HitBall(FVector Direction, float Power);	
	
	UFUNCTION(BlueprintCallable)
	void TryToGrabBall();
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	bool IsGk;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References", meta = (AllowPrivateAccess = "true"))
	ABallActor* Ball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	EPositions Position;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	ATeam* Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TeamType", meta = (AllowPrivateAccess = "true"))
	ETeamTypes TeamType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta=(AllowPrivateAccess="true"))
	AMatchManager* MatchManager;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References", meta = (AllowPrivateAccess = "true"))
	AGoalNet* GoalNet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References", meta = (AllowPrivateAccess = "true"))
	AGoalNet* TargetGoalNet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta = (AllowPrivateAccess = "true"))
	UAttributeComponent* Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Status", meta = (AllowPrivateAccess = "true"))
	UAnimationComponent* Animator;

protected:
	
private:	
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BallHoldComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(AllowPrivateAccess="true"))
	UBoxComponent* RightFootCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(AllowPrivateAccess="true"))
	UBoxComponent* RightLegCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(AllowPrivateAccess="true"))
	UBoxComponent* LeftLegCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(AllowPrivateAccess="true"))
	UBoxComponent* BodyCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Select", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* PlayerSelectedMark;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Select", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* PlayerDirectionArrow;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sounds", meta = (AllowPrivateAccess = "true"))
	USoundBase* HitSound;

	UPROPERTY()
	FTimerHandle TimerHandler;

	UPROPERTY()
	FVector BallTargetLocation;
	UPROPERTY()
	FVector StartLocation;
	UPROPERTY()
	FVector TargetMoveLocation;

	UFUNCTION()
	void UpdateStatus();
	
	UFUNCTION()
	void UpdateSkillMove();
	
public:
	
	UPROPERTY()
	float PlayerFieldProgress;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Status", meta=(AllowPrivateAccess="true"))
	EActs CurrentAct;
	
	UFUNCTION(BlueprintCallable)
	void ApplyBehavior();

	UFUNCTION()
	void FinishAllActions();
	UFUNCTION()
	void FinishActionBallHit();
	UFUNCTION()
	void FinishActionStruggle();
	UFUNCTION()
	void FinishActionCheerOrSad();
	UFUNCTION()
	void FinishActionTackle();
	UFUNCTION()
	void FinishActionCross();
	
	UFUNCTION()
	bool IsReachedToTarget(FVector TargetLocation);

	UFUNCTION()
	void BallPassedToMe();

public:
	void UpdateActionStartTime(EActs act);
	//***************************************************************************************************
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Defending Status", meta=(AllowPrivateAccess="true"))
	bool IsDefending = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Ball Status", meta=(AllowPrivateAccess="true"))
	bool IsHoldingBall = false;
	
	UPROPERTY()
	bool CanControl = false;

	UPROPERTY()
	bool IsDashing = false;

	UPROPERTY()
	bool IsTackling = false;

	UPROPERTY()
	bool WaitForBall = false;
	
	UPROPERTY()
	bool IsCrossing = false;
	
	UPROPERTY()
	double MatchStartTime;

	UPROPERTY()
	double TackleActionStartTime = -1;

	UPROPERTY()
	double CrossActionStartTime = -1;

	UPROPERTY()
	double StruggleActionStartTime = -1;

	UPROPERTY()
	double BallHitActionStartTime;

	UPROPERTY()
	double BallPassedStartTime = -1;
	
	UPROPERTY()
	double CurrentTime;


public:
	
	UFUNCTION()
	TArray<AFootballPlayer*> GetTeammatesInMyArea(bool FromCurrentLocation);
	UFUNCTION()
	TArray<AFootballPlayer*> GetOpponentsInMyArea(bool FromCurrentLocation);
	UFUNCTION()
	TArray<AFootballPlayer*> GetBestTeammatesToPass();
	
	UFUNCTION()
	void BehaviorTacticPositioning();

	UPROPERTY()
	bool IsRunningForwardWithBall = false;
	UFUNCTION()
	void BehaviorRunForwardWithBall();
	

	UFUNCTION()
	void BehaviorRunBehindDefenseLine();
	
	UFUNCTION()  
	void BehaviorDefense();

	UFUNCTION()
	void BehaviorAttack();

	UFUNCTION()
	void BehaviorPass();

	UFUNCTION()
	void BehaviorShoot();

	UFUNCTION()
	void ChaseBall();

	UFUNCTION()
	void CheckEnvironment();
};
