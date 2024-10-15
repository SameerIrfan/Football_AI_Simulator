#pragma once

UENUM(BlueprintType)
enum class EActionState : uint8
{
	None UMETA(DisplayName = "None"),
	Pass UMETA(DisplayName = "Pass"),
	Shoot UMETA(DisplayName = "Shoot"),
	BallStop UMETA(DisplayName = "BallStop"),
	Tackle UMETA(DisplayName = "Tackle"),
	Cross UMETA(DisplayName = "Cross"),
	Kick UMETA(DisplayName = "Kick"),
	LossBalance UMETA(DisplayName = "LossBalance"),
	Cheer UMETA(DisplayName="Cheer"),
	Sad UMETA(DisplayName ="Sad"),
	ThrowBall UMETA(DisplayName="ThrowBall")
};
