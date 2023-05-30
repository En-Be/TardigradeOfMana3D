// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

#include "MyPlayerCharacter.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("Bang!"));
	//UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UNiagaraFunctionLibrary::SpawnSystemAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"), FVector(0.f), FRotator(0.f), EAttachLocation::Type::KeepRelativeOffset, true);
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));

	FHitResult Hit;
	FVector ShotDirection;
	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{
		AActor* HitActor = Hit.GetActor();
		UStaticMeshComponent* MeshComp = HitActor->FindComponentByClass<UStaticMeshComponent>();
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		//UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), MuzzleFlash, Hit.Location, FRotator(0.f), FVector(0.f), EAttachLocation::Type::KeepRelativeOffset, true);
		if (MeshComp != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("FoundTarget"));
			UNiagaraFunctionLibrary::SpawnSystemAttached(MuzzleFlash, MeshComp, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::Type::KeepRelativeOffset, true);
		}

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
		if (HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			AController* OwnerController = GetOwnerController();
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
			
			ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
			AMyPlayerCharacter* OwnerCharacter = Cast<AMyPlayerCharacter>(myCharacter);
			if (OwnerCharacter != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cast worked"));
				OwnerCharacter->TakeDamage(Damage*-1, DamageEvent, OwnerController, this);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Cast failed"));
			}
		}
	}

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)
		return false;

	FVector Location;
	FRotator Rotation;

	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * MaxRange;

	Hit;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) 
		return nullptr;
	return OwnerPawn->GetController();
}

