#pragma once
UENUM(BlueprintType)
enum class EBallHitAnimationEvent :uint8
{
    None UMETA(DisplayName = "None"),
    Pass UMETA(DisplayName = "Pass"),
    LongBall UMETA(DisplayName = "LongBall"),
    Shoot UMETA(DisplayName = "Shoot")
};