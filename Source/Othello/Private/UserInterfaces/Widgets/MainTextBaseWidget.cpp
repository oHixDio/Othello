// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/MainTextBaseWidget.h"
#include "Components/TextBlock.h"

void UMainTextBaseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	SetText(FText::FromString("Main"));
}

void UMainTextBaseWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	SetText(NewMainText);
}

void UMainTextBaseWidget::SetText(FText NewText)
{
	if (MainText)
	{
		MainText->SetText(NewText);
	}
}
