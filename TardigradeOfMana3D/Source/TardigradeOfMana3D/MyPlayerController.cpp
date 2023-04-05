// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "TimerManager.h"

void AMyPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UE_LOG(LogTemp, Warning, TEXT("We Have finished."))

		GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}