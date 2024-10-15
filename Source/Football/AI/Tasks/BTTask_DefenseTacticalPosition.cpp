// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DefenseTacticalPosition.h"

#include "Football/Ball/BallActor.h"

UBTTask_DefenseTacticalPosition::UBTTask_DefenseTacticalPosition(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Defense Tactical Position";
}

EBTNodeResult::Type UBTTask_DefenseTacticalPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::InitVariables(OwnerComp);
	FVector BallPosition = Ball->GetActorLocation();
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
