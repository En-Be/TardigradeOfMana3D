// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UE_LOG(LogTemp, Warning, TEXT("We Have finished."))

	UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
	if (LoseScreen != nullptr)
	{
		LoseScreen->AddToViewport();
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}