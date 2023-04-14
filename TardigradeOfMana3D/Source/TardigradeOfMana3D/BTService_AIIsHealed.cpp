// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_AIIsHealed.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "MyPlayerCharacter.h"

UBTService_AIIsHealed::UBTService_AIIsHealed()
{
	NodeName = "AI Is Healed";
}

void UBTService_AIIsHealed::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	/*
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AMyPlayerCharacter* ControlledCharacter = Cast<AMyPlayerCharacter>(GetPawn());

	if (ControlledCharacter == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled character is null"));

		return;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), ControlledCharacter->IsHealed());
	*/
}
