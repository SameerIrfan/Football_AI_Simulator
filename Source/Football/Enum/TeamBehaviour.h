#pragma once
UENUM(BlueprintType)
enum class ETeamBehaviour :uint8
{
	Defending UMETA(DisplayName = "Defending"),
		// Defending means you don't have the ball and trying to get the ball.
	Attacking UMETA(DisplayName = "Attacking"),
		// Attacking means you have the ball, and the players will get closer to the ball and move forward by the ball.
	BallChasing UMETA(DisplayName = "BallChasing"),
		// Ball is free at the moment.
	WaitingForTeamGk UMETA(DisplayName = "WaitingForTeamGK"),
		// Our keeper has the ball.
	WaitingForOpponentGk UMETA(DisplayName = "WaitingForOpponentGK"),
		// OpponentGK has the ball.
	TeamThrowIn UMETA(DisplayName = "TeamThrowIn"),
	OpponentThrowIn UMETA(DisplayName = "OpponentThrowIn")
};
