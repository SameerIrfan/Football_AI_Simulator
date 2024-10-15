// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PursuitScorable.h"
#include "PursuitTracker.generated.h"



UCLASS()
class FOOTBALL_SIM_API UPursuitTracker : public UObject
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere, meta=(ExposeOnSpawn=true) )
	TArray<TScriptInterface<IPursuitScorable>> tracking {};

	UFUNCTION(BlueprintCallable)
	void Refresh();
	
	UFUNCTION(BlueprintCallable)
	TArray<TScriptInterface<IPursuitScorable>> GetSortedScorables() const;
};
