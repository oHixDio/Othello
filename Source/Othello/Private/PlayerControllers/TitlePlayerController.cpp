// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/TitlePlayerController.h"

#include "HUDs/TitleHUD.h"
#include "UserInterfaces/MainWidgets/TitleMainWidget.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ATitlePlayerController::ATitlePlayerController()
{
	bShowMouseCursor = true;
}

void ATitlePlayerController::BeginPlay()
{
	Super::BeginPlay();
	// SetInputMode(FInputModeUIOnly());

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(TitleMappingContext, 0);
	}
	
}

void ATitlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(SelectableColAction, ETriggerEvent::Started, this, &ATitlePlayerController::OnSelectCol);
	}
}

void ATitlePlayerController::OnSelectCol(const FInputActionValue& Value)
{
	float InputValue = Value.Get<float>();

	int32 Index = InputValue > 0 ? 1 : -1;

	ATitleHUD* HUD = GetHUD<ATitleHUD>();
	if (HUD)
	{
		int32 ChangedIndex = HUD->GetTitleWidget()->ChangeSelectButton(Index);
	}
}

void ATitlePlayerController::OnSelectRow(const FInputActionValue& Value)
{
	float InputValue = Value.Get<float>();
}

void ATitlePlayerController::OnDone(const FInputActionValue& Value)
{
	ATitleHUD* HUD = GetHUD<ATitleHUD>();
	if (HUD)
	{

	}

}

void ATitlePlayerController::OnBack(const FInputActionValue& Value)
{
}
