// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/GameSelectPlayerController.h"

AGameSelectPlayerController::AGameSelectPlayerController()
{
	bShowMouseCursor = true;
}

void AGameSelectPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AGameSelectPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
