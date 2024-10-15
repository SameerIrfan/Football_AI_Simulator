#pragma once
UENUM(BlueprintType)
enum class EMovementType : uint8 {
    Relax UMETA(DisplayName = "Relax"),
    Normal UMETA(DisplayName = "Normal"),
    BestHeCanDo UMETA(DisplayName = "BestHeCanDo")
};