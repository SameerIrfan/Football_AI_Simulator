#pragma once

UENUM(BlueprintType)
enum class EAILevel : uint8
{
    Amateur UMETA(DisplayName = "Amateur"),
    SemiPro UMETA(DisplayName = "SemiPro"),
    Professional UMETA(DisplayName = "Professional"),
    WorldClass UMETA(DisplayName = "WorldClass"),
    Legendary UMETA(DisplayName = "Legendary")
};
