// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "AIController.h"
#include "PodCreature.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName = "Attack";
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	Creature->Attack();
	return EBTNodeResult::Succeeded;
}