// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Patrol.h"
#include "AIController.h"
#include "PodCreature.h"

UBTTask_Patrol::UBTTask_Patrol()
{
	NodeName = "Patrol";
}

EBTNodeResult::Type UBTTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	APodCreature* Creature = Cast<APodCreature>(OwnerComp.GetAIOwner()->GetPawn());
	if (Creature == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Creature->Patrol();
	return EBTNodeResult::Succeeded;
}