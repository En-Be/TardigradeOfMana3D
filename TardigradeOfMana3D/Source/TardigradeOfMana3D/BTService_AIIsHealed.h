// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_AIIsHealed.generated.h"


UCLASS()
class TARDIGRADEOFMANA3D_API UBTService_AIIsHealed : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_AIIsHealed();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
