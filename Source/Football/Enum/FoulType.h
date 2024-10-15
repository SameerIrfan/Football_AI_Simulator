#pragma once
UENUM(BlueprintType)
enum class EFoulType:uint8 {
    Foul UMETA(DisplayName = "Foul"),
    ThrowIn UMETA(DisplayName = "ThrowIn"),
    GoalKick UMETA(DisplayName = "GoalKick")
};