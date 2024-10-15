#pragma once
UENUM(BlueprintType)
enum class EMatchStatus :uint8 {
    NotPlaying UMETA(DisplayName = "NotPlaying"),
    WaitingForKickOff UMETA(DisplayName = "WaitingForKickOff"),
    Playing UMETA(DisplayName = "Playing"),
    Freeze UMETA(DisplayName = "Freeze"),
    Special UMETA(DisplayName = "Special")
};
