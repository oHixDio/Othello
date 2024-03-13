// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/MyHUD.h"

#include "UserInterfaces/Widgets/FadeWidget.h"

AMyHUD::AMyHUD()
{
}

void AMyHUD::FadeIn()
{
	if (FadeWidget)
	{
		FadeWidget->FadeIn();
	}
	
}

void AMyHUD::FadeOut(TSoftObjectPtr<UWorld> Level)
{
	if (FadeWidget)
	{
		FadeWidget->FadeOut(Level);
	}
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	if (FadeWidgetClass)
	{
		FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeWidgetClass);
		FadeWidget->AddToViewport(9999);
		FadeWidget->SetVisibility(ESlateVisibility::Visible);
	}
}
