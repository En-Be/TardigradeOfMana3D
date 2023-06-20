// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "TardigradeOfMana3DGameModeBase.h"

// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth/10;

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

bool AMyPlayerCharacter::IsDead() const
{
	return Health <= 0;
}

bool AMyPlayerCharacter::IsHealed() const
{
	return Health >= MaxHealth;
}

float AMyPlayerCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForwardAndBack"), this, &AMyPlayerCharacter::MoveForwardAndBack);
	PlayerInputComponent->BindAxis(TEXT("MoveSideways"), this, &AMyPlayerCharacter::MoveSideways);
	PlayerInputComponent->BindAxis(TEXT("LookUpAndDown"), this, &AMyPlayerCharacter::LookUpAndDown);
	PlayerInputComponent->BindAxis(TEXT("LookSideways"), this, &AMyPlayerCharacter::LookSideways);
	//PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AMyPlayerCharacter::Shoot);
}

float AMyPlayerCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	Health = FMath::Clamp(Health, 0, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Health remaining %f"), Health);

	if (IsDead())
	{
		ATardigradeOfMana3DGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATardigradeOfMana3DGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

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

void AMyPlayerCharacter::MoveForwardAndBack(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AMyPlayerCharacter::MoveSideways(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AMyPlayerCharacter::LookUpAndDown(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMyPlayerCharacter::LookSideways(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AMyPlayerCharacter::Shoot()
{
	Gun->PullTrigger();
}
