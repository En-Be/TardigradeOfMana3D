// Fill out your copyright notice in the Description page of Project Settings.


#include "PodCreature.h"
#include "TardigradeOfMana3DGameModeBase.h"

// Sets default values
APodCreature::APodCreature()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APodCreature::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth / 10;

	Attacking = false;
}

// Called every frame
void APodCreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APodCreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool APodCreature::IsHealed() const
{
	return Health >= MaxHealth;
}

bool APodCreature::IsAttacking() const
{
	return Attacking;
}

void APodCreature::Attack()
{
	Attacking = true;
}

void APodCreature::Patrol()
{
	Attacking = false;
}

float APodCreature::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	Health = FMath::Clamp(Health, 0, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Health remaining %f"), Health);

	if (IsHealed())
	{
		ATardigradeOfMana3DGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATardigradeOfMana3DGameModeBase>();
		if (GameMode != nullptr)
		{
			//GameMode->PawnHealed(this);
		}
	}

	return DamageToApply;
}

