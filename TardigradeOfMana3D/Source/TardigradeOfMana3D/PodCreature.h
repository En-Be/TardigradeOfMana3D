// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PodCreature.generated.h"

UCLASS()
class TARDIGRADEOFMANA3D_API APodCreature : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APodCreature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	UFUNCTION(BlueprintPure)
		bool IsHealed() const;

	UFUNCTION(BlueprintPure)
		bool IsAttacking() const;

	void Attack();

	void Patrol();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;


private:
	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		float Health;

	UPROPERTY(VisibleAnywhere)
		bool Attacking;
};
