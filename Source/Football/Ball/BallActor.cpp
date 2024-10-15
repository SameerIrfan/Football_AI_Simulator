// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "Components/SphereComponent.h"
#include "Curves/CurveFloat.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"
#include <Components/TimelineComponent.h>
#include <Football/DebugMacros.h>

#include "EngineUtils.h"
#include "Football/Players/FootballPlayer.h"
// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpherePhysics = CreateDefaultSubobject<USphereComponent>(TEXT("SpherePhysics"));

	RootComponent = SpherePhysics;

    BallCollision = CreateDefaultSubobject<USphereComponent>(TEXT("BallCollision"));
    BallCollision->SetupAttachment(GetRootComponent());

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMeshComponent"));
	BallMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BallMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BallMesh->SetupAttachment(BallCollision);

	FTimeline TimelineRecoil;

	/*followSpeedCurve = NewObject<UCurveFloat>(this);
	followSpeedCurve->FloatCurve.UpdateOrAddKey(0.f, 0.f);
	followSpeedCurve->FloatCurve.UpdateOrAddKey(1.f, 1.f);*/
	//TimelineRecoil.AddInterpFloat(followSpeedCurve, ProgressInTimeline);
}

FVector ABallActor::BallPosition(AFootballPlayer* player, float relaxation)
{
	//return player->GetBallPosition();
    return FVector();// Predicter(player, relaxation);
}


void ABallActor::Hold(AFootballPlayer* Player)
{
	if( HolderPlayer )
	{
		HolderPlayer->ReleaseBall();
	}
    LastTouchedPlayer = Player;
    
    HolderPlayer = Player;

	SpherePhysics->SetSimulatePhysics(false);
    SpherePhysics->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	HolderTeam = HolderPlayer->Team;
	
	HolderPlayer->HoldBall();
	
}

void ABallActor::Release()
{
	LastHolder = HolderPlayer;

	if (HolderPlayer) {
		HolderPlayer->ReleaseBall();
	}

	HolderPlayer = nullptr;
	HolderTeam = nullptr;
	
    SpherePhysics->SetSimulatePhysics(true);
    SpherePhysics->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

bool ABallActor::HolderBehave(FVector position, float deltaTime, float speedMod)
{
	return  false;
}


// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
}

void ABallActor::BallHit(AFootballPlayer* hitter, FVector velocity, bool ignoreOffside)
{
	SpherePhysics->SetAllPhysicsLinearVelocity(velocity, false);
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);    
}

ABallActor* ABallActor::GetWorldBall(UWorld* World)
{
	//TActorIterator<ABall> ActorIterator = TActorIterator<ABall>(World);
	for (TActorIterator<ABallActor> ActorIterator{ World }; ActorIterator; ++ActorIterator) {
		return *ActorIterator;
	}
	return nullptr;
}

