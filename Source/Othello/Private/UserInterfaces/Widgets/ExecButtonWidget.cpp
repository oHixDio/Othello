// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/ExecButtonWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UExecButtonWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UExecButtonWidget::NativePreConstruct()
{
	Super::NativeOnInitialized();

	if (ExecText)
	{
		ExecText->SetText(CurExecText);
	}
}
