// Fill out your copyright notice in the Description page of Project Settings.

#include "PursuitTracker.h"
#include "PursuitScorable.h"
void UPursuitTracker::Refresh()
{
    UE_LOG(LogTemp, Warning, TEXT("Refreshing List"));
}


TArray<TScriptInterface<IPursuitScorable>> UPursuitTracker::GetSortedScorables() const
{
    // Create a copy of the array to sort
    TArray<TScriptInterface<IPursuitScorable>> SortedArray = tracking;

    // Lambda function to compare getCost values
    SortedArray.Sort([](const TScriptInterface<IPursuitScorable>& A, const TScriptInterface<IPursuitScorable>& B)
    {
        return A->getCost() > B->getCost();
    });

    return SortedArray;
}