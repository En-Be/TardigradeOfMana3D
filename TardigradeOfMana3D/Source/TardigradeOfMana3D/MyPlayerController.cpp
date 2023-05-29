// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}

void AMyPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	UE_LOG(LogTemp, Warning, TEXT("We Have finished."))

	if (bIsWinner)
	{
		OpenGate = true;
		/*
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
		*/
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}


	//GetWorldTimerManager().SetTimer(RestartTimer, this, &AMyPlayerController::GoToMenu, RestartDelay);
}

void AMyPlayerController::GoToMenu()
{
	UGameplayStatics::OpenLevel(this, "Menu");
}


