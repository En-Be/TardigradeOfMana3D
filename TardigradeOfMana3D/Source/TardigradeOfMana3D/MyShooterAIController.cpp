// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AMyShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	SetFocus(PlayerPawn);
}

void AMyShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	MoveToActor(PlayerPawn, 200);

}