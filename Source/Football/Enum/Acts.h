#pragma once
UENUM(BlueprintType)
enum class EActs : uint8 {
    None = 0 UMETA(DisplayName = "None"),
    GoingToGoal = 1 UMETA(DisplayName = "GoingToGoal"),
    Crossing = 2 UMETA(DisplayName = "Crossing"),
    Shoot = 3 UMETA(DisplayName = "Shoot"),
    Cheer = 4 UMETA(DisplayName = "Cheer"),
    Sad = 5 UMETA(DisplayName = "Sad"),
    GoingToTackle = 6 UMETA(DisplayName = "GoingToTackle"),
    Tackling = 7 UMETA(DisplayName = "Tackling"),
    Dashing = 8 UMETA(DisplayName = "Dashing"),
    Stunned = 9 UMETA(DisplayName = "Stunned"),
    MarkingTheOpponent UMETA(DisplayName = "Balanced"),
    GoingToGetTheBall_BallChasing UMETA(DisplayName = "GoingToGetTheBall_BallChasing"),
    GoingToGetTheBall_WithCaution UMETA(DisplayName = "GoingToGetTheBall_WithCaution"),
    RunningForward UMETA(DisplayName = "RunningForward"),
    RunningBehindTheDefenseLine UMETA(DisplayName = "RunningBehindTheDefenseLine"),
    PassingToBehindTheDefenseLine UMETA(DisplayName = "PassingToBehindTheDefenseLine"),
    ThrowIn UMETA(DisplayName = "ThrowIn"),
    StrikerTactical UMETA(DisplayName = "StrikerTactical"),
    TacticalPositioning UMETA(DisplayName = "TacticalPositioning"),
    DefensiveTacticalPositioning UMETA(DisplayName = "DefensiveTacticalPositioning"),
    JoinTheAttack UMETA(DisplayName = "JoinTheAttack"),
    PassAndRun UMETA(DisplayName = "PassAndRun"),
    MarkTheLastGuy UMETA(DisplayName = "MarkTheLastGuy"),
    Dribbling UMETA(DisplayName = "Dribbling")
};