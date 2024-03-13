// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/GameSelectHUD.h"

#include "UserInterfaces/MainWidgets/GameSelectMainWidget.h"

AGameSelectHUD::AGameSelectHUD()
{
}

void AGameSelectHUD::BeginPlay()
{
	Super::BeginPlay();

	FadeIn();UE_LOG(LogTemp, Warning, TEXT("GameSelectHUD"));

	if (GameSelectMainWidgetClass)
	{
		GameSelectMainWidget = CreateWidget<UGameSelectMainWidget>(GetWorld(), GameSelectMainWidgetClass);
		GameSelectMainWidget->AddToPlayerScreen(0);
	}

}
