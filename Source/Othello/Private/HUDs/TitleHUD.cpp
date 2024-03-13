// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/TitleHUD.h"
#include "UserInterfaces/MainWidgets/TitleMainWidget.h"



ATitleHUD::ATitleHUD()
{
}

void ATitleHUD::BeginPlay()
{
	Super::BeginPlay();

	FadeIn();

	if (TitleMainWidgetClass)
	{
		TitleMainWidget = CreateWidget<UTitleMainWidget>(GetWorld(), TitleMainWidgetClass);
		TitleMainWidget->AddToPlayerScreen(0);
	}
	
}
