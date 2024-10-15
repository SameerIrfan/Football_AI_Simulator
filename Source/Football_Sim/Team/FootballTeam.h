#pragma once
#include "CoreMinimal.h"


#include "FootballTeam.generated.h"

UENUM(BlueprintType)
enum class EFootballTeam : uint8
{
    HOME UMETA(DisplayName="Home"),
    AWAY UMETA(DisplayName="Away"),
};