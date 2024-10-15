// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalNet.h"

#include "EngineUtils.h"
#include "Components/BoxComponent.h"
#include "Football/Ball/BallActor.h"
#include "Football/Core/MatchManager.h"
#include "Football/Players/FootballPlayer.h"

// Sets default values
AGoalNet::AGoalNet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoalNetMesh"));
	RootComponent = Mesh;
	
	GoalNetCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("GoalNetCollision"));
	GoalNetCollision->SetupAttachment(GetRootComponent());

	for (int i = 0; i < 21; i++)
	{
		FName const TargetName = *FString::Printf(TEXT("GoalTarget%i"), i);
		UStaticMeshComponent* GoalTargetTemp = CreateDefaultSubobject<UStaticMeshComponent>(TargetName);
		GoalTargetTemp->SetupAttachment(GetRootComponent());
		GoalTargets.Add(GoalTargetTemp);
	}

	for (int i = 1; i <= 4; i++)
	{
		FName const OutCollisionName = *FString::Printf(TEXT("OutCollision%i"), i);
		UBoxComponent* OutCollision = CreateDefaultSubobject<UBoxComponent>(OutCollisionName);
		OutCollision->SetupAttachment(GetRootComponent());
		GoalNetOutCollisions.Add(OutCollision);
	}
	
	
}

void AGoalNet::GoalIn()
{
	if( IsGoal == false)
	{
		IsGoal = true;
		if( Ball->LastTouchedPlayer != nullptr)
		{
			Ball->LastTouchedPlayer->Cheers();
		}
		MatchManager->MatchStatus = EMatchStatus::WaitingForKickOff;
	}
}
// Called when the game starts or when spawned
void AGoalNet::BeginPlay()
{
	Super::BeginPlay();
	//MatchManager = AMatchManager::GetMatchManager(GetWorld());
	//Ball = ABall::GetWorldBall(GetWorld());
}

// Called every frame
void AGoalNet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AGoalNet* AGoalNet::GetGoalNet(UWorld* World, const ETeamTypes MyTeamType)
{
	TActorIterator<AGoalNet> ActorIterator(World);
	for (; ActorIterator; ++ActorIterator) {
		if(ActorIterator->TeamType == MyTeamType)
		{
			return *ActorIterator;
		}
	}
	return nullptr;
}

FVector AGoalNet::GetRandomGoalTarget()
{
	int index = FMath::RandRange(0, GoalTargets.Num()-1);
	index = 0;
	return GoalTargets[index]->GetComponentLocation();
}

