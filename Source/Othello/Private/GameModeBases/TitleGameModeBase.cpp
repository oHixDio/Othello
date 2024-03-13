// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBases/TitleGameModeBase.h"

#include "GameInstances/MyGameInstance.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


ATitleGameModeBase::ATitleGameModeBase()
{
}

void ATitleGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

////////////////////////////////
// Player人数Modeを決める

void ATitleGameModeBase::DecideNumOfPlayerMode()
{
}
//==============================

////////////////////////////////
// Gameを終了させる機能

void ATitleGameModeBase::ExitGame(APlayerController* PlayerController)
{
	UKismetSystemLibrary::QuitGame(this, PlayerController, EQuitPreference::Quit, false);
}
//==============================