// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/GameTitleWidget.h"

#include "Components/TextBlock.h"

void UGameTitleWidget::UpdateWidget(const FText TitleText)
{
	GameTitleText->SetText(TitleText);
}

void UGameTitleWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	GameTitleText->SetText(FText::FromString(TEXT("Game")));
	FadeOut();
}
