// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationComponent.h"

#include "FootballPlayer.h"

// Sets default values for this component's properties
UAnimationComponent::UAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAnimationComponent::PlayBallStopMontage()
{
	PlayMontageSection(BallStopMontage, FName("FootStopL"));
}

void UAnimationComponent::PlayShootMontage()
{
	PlayMontageSection(ShootMontage, FName("ShootNormal"));
}

void UAnimationComponent::PlayPassMontage()
{
	PlayRandomMontageSection(PassMontage, PassMontageSections);
}

void UAnimationComponent::PlayTackleMontage(bool IsSliding)
{
	if( IsSliding )
	{
		PlayMontageSection(TackleMontage, FName("TackleL"));
	}
	else
	{
		PlayMontageSection(TackleMontage, FName("TackleSlide"));
	}
}

void UAnimationComponent::PlayCrossMontage(bool IsAttacking)
{
	if( IsAttacking )
	{
		const int AttackType = FMath::RandRange(1, 5);
		const FString Name = FString::Printf(TEXT("CrossAttack%d"),AttackType);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Name);
		PlayMontageSection(CrossMontage, FName(*Name));
	}else
	{
		PlayMontageSection(CrossMontage, FName("CrossDefend1"));
	}
}

void UAnimationComponent::PlayCheerMontage()
{
	PlayRandomMontageSection(CheerMontage, CheerMontageSections);
}

void UAnimationComponent::PlaySadMontage()
{
	PlayRandomMontageSection(SadMontage, SadMontageSections);
}


// Called when the game starts
void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAnimationComponent::PlayMontageSection(UAnimMontage* Montage, const FName& SectionName)
{
	if( PlayerRef )
	{
		UAnimInstance* AnimInstance = PlayerRef->GetMesh()->GetAnimInstance();
		if (AnimInstance && Montage)
		{
			AnimInstance->Montage_Play(Montage, 1.5f);
			AnimInstance->Montage_JumpToSection(SectionName, Montage);
		}
	}
	
}

int32 UAnimationComponent::PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames)
{
	if (SectionNames.Num() <= 0) return -1;
	const int32 MaxSectionIndex = SectionNames.Num() - 1;
	const int32 Selection = FMath::RandRange(0, MaxSectionIndex);
	PlayMontageSection(Montage, SectionNames[Selection]);
	return Selection;
}

