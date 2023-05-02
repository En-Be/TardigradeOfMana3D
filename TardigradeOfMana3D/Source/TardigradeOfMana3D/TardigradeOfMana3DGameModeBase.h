// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TardigradeOfMana3DGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TARDIGRADEOFMANA3D_API ATardigradeOfMana3DGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* PawnKilled);
	virtual void PawnHealed(APawn* PawnHealed);

};
