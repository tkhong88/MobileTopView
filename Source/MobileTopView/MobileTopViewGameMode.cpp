// Copyright Epic Games, Inc. All Rights Reserved.

#include "MobileTopViewGameMode.h"
#include "MobileTopViewPlayerController.h"
#include "MobileTopViewCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMobileTopViewGameMode::AMobileTopViewGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMobileTopViewPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	USN = 0;
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/BP_CharacterFemaleA"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
int	AMobileTopViewGameMode::GenerateSN()
{
	csUSN.Lock();
	USN++;
	csUSN.Unlock();
	return USN;
}