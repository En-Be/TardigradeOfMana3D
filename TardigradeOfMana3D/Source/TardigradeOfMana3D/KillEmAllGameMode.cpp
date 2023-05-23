// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "MyShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	UE_LOG(LogTemp, Warning, TEXT("A pawn was killed"));

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Killed pawn is player"));

		for (AMyShooterAIController* Controller : TActorRange<AMyShooterAIController>(GetWorld()))
		{
			Controller->PlayerDied();
		}

		EndGame(false);
	}	

	for (AMyShooterAIController* Controller : TActorRange<AMyShooterAIController>(GetWorld()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Checking if any ai aren't dead"));

		if (!Controller->IsDead())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Checking if any ai aren't dead"));

			return;
		}
	}

	EndGame(true);
}

void AKillEmAllGameMode::PawnHealed(APawn* PawnHealed)
{
	Super::PawnHealed(PawnHealed);

	UE_LOG(LogTemp, Warning, TEXT("A pawn was healed"));

	APlayerController* PlayerController = Cast<APlayerController>(PawnHealed->GetController());
	if (PlayerController != nullptr)
	{
		//EndGame(false);
	}

	for (AMyShooterAIController* Controller : TActorRange<AMyShooterAIController>(GetWorld()))
	{
		if (!Controller->IsHealed())
		{
			UE_LOG(LogTemp, Warning, TEXT("At least one not healed"));
			return;
		}
	}

	OpenGate();
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}

void AKillEmAllGameMode::OpenGate()
{
	UE_LOG(LogTemp, Warning, TEXT("All pawns are healed"));
	EndGame(true);
	/*
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
	*/
}
