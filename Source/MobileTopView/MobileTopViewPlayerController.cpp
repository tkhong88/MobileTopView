// Copyright Epic Games, Inc. All Rights Reserved.

#include "MobileTopViewPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "MobileTopViewCharacter.h"
#include "Engine/World.h"

AMobileTopViewPlayerController::AMobileTopViewPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AMobileTopViewPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AMobileTopViewPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AMobileTopViewPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AMobileTopViewPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AMobileTopViewPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AMobileTopViewPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AMobileTopViewPlayerController::OnResetVR);
}

void AMobileTopViewPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}
bool AMobileTopViewPlayerController::ProcessActorClick(AActor* pActor)
{
	if (pActor != nullptr) {
		if (pActor->ActorHasTag(FName(TEXT("Clickable")))) {
			AMobileTopViewCharacter* pChar = dynamic_cast<AMobileTopViewCharacter*>(GetCharacter());
			pChar->Clicked(pActor);
			return true;
		}
	}
	return false;
}

void AMobileTopViewPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AMobileTopViewCharacter* MyPawn = Cast<AMobileTopViewCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			if (ProcessActorClick(Hit.GetActor()))
			{
				return;
			}
			/*
			AActor* pActor = Hit.GetActor();
			if (pActor != nullptr) {
				if (pActor->ActorHasTag(FName(TEXT("Enemy")))) {
					AMobileTopViewCharacter* pChar = dynamic_cast<AMobileTopViewCharacter*>(GetCharacter());
					pChar->Clicked(pActor);
					return;
				}
			}
			*/
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AMobileTopViewPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		if (ProcessActorClick(HitResult.GetActor()))
		{
			return;
		}
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AMobileTopViewPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
		AMobileTopViewCharacter* pChar = dynamic_cast<AMobileTopViewCharacter *>(MyPawn);
		//pChar->Clicked();
	}
}

void AMobileTopViewPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AMobileTopViewPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
