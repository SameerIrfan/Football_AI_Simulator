#pragma once
UENUM(BlueprintType)
enum class TacticPresetTypes : uint8
{
    Balanced = 3 UMETA(DisplayName = "Balanced"),
    Offensive = 5 UMETA(DisplayName = "Offensive"),
    CounterAttack = 2 UMETA(DisplayName = "CounterAttack"),
    ParkTheBus = 0 UMETA(DisplayName = "ParkTheBus"),
    HighPressure = 4 UMETA(DisplayName = "HighPressure"),
    Defensive = 1 UMETA(DisplayName = "Defensive"),
    ParameterCount = 6 UMETA(DisplayName = "ParameterCount")
};