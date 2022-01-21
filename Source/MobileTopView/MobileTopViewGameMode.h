// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MobileTopViewGameMode.generated.h"

UCLASS(minimalapi)
class AMobileTopViewGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMobileTopViewGameMode();
	UFUNCTION(BlueprintCallable, Category = "GlobalSet")
	int	GenerateSN();

private:
	int		USN;
	FCriticalSection	csUSN;


};



