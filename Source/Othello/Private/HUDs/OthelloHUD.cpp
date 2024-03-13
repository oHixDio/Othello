// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/OthelloHUD.h"

#include "UserInterfaces/MainWidgets/OthelloMainWidget.h"

AOthelloHUD::AOthelloHUD()
{
}

void AOthelloHUD::BeginPlay()
{
	Super::BeginPlay();

	FadeIn();

	if (MainWidgetClass)
	{
		MainWidget = CreateWidget<UOthelloMainWidget>(GetWorld(), MainWidgetClass);
		MainWidget->AddToPlayerScreen(0);
	}
}
