// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyPlayerCharacter.h"
#include "PodCreature.h"

void AMyShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

	}
}

void AMyShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMyShooterAIController::PlayerDied()
{
	UE_LOG(LogTemp, Warning, TEXT("Player has died"));
	GetBlackboardComponent()->SetValueAsBool(TEXT("PlayerDied"), true);
	
}

bool AMyShooterAIController::IsDead() const
{
	APodCreature* ControlledCharacter = Cast<APodCreature>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}
	
	return true;
}

bool AMyShooterAIController::IsHealed() const
{
	APodCreature* ControlledCharacter = Cast<APodCreature>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsHealed();
		//GetBlackboardComponent()->SetValueAsBoolean(TEXT("IsHealed"), GetPawn()->true);
	}

	return true;
}