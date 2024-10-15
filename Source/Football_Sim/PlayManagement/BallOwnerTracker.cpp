// Fill out your copyright notice in the Description page of Project Settings.


#include "BallOwnerTracker.h"

#include "Football_Sim/AI/BallBindings/CanBeStolenFrom.h"


// Sets default values for this component's properties
UBallOwnerTracker::UBallOwnerTracker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBallOwnerTracker::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBallOwnerTracker::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	
}

void UBallOwnerTracker::NotifyPlayerReceiveBall(AActor* Player)
{
	LastBallHolder = CurrentBallHolder;
	CurrentBallHolder = Player;
	PlayerReceivedBall.Broadcast(Player);
}

void UBallOwnerTracker::NotifyBallLeftPlayer(AActor* LastPlayer)
{
	LastBallHolder = CurrentBallHolder;
	CurrentBallHolder = nullptr;
	PlayerLeftBall.Broadcast(LastPlayer);
}

void UBallOwnerTracker::NotifyTackleOccurred(TScriptInterface<ICanBeStolenFrom> defender,
	TScriptInterface<ICanStealBall> challenger, TScriptInterface<IBall> ball)
{
	UObject* defenderObject = defender.GetObject();
	if(!defenderObject)
	{
		UE_LOG(LogActor, Error, TEXT("The defender object is invalid"));
		return;
	}
	AActor* defenderActor = Cast<AActor>(defenderObject);
	if(!defenderActor)
	{
		UE_LOG(LogActor, Error, TEXT("The defender actor is invalid"));
		return;
	}

	UObject* challengerObject = challenger.GetObject();
	if(!challengerObject)
	{
		UE_LOG(LogActor, Error, TEXT("The challenger object is invalid"));
		return;
	}
	LastBallHolder = defenderActor;
	AActor* challengerActor = Cast<AActor>(challengerObject);
	if(!challengerActor)
	{
		UE_LOG(LogActor, Error, TEXT("The challenger actor is invalid"));
		return;
	}
	CurrentBallHolder = challengerActor;
	TackleOccured.Broadcast(defender, challenger, ball);
	
}

void UBallOwnerTracker::NotifyPlayerShotBall(AController* Shooter)
{
}

