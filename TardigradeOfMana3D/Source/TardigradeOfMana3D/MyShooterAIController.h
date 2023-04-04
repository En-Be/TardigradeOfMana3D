// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class TARDIGRADEOFMANA3D_API AMyShooterAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;
};
