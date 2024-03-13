// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/SelectNumberWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void USelectNumberWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	Number = 1;
	MaxNumber = 99;
	bPlayAnim = false;

	// Clickイベントに関数をバインド
	if (LeftButton)
	{
		LeftButton->OnClicked.AddDynamic(this, &USelectNumberWidget::OnLeftClick);
	}
	if (RightButton)
	{
		RightButton->OnClicked.AddDynamic(this, &USelectNumberWidget::OnRightClick);
	}
	
	// AnimFinishedイベントに関数をバインド
	EndDelegate.BindDynamic(this, &USelectNumberWidget::AnimationFinished);
	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(Zoom, EndDelegate);
	}
}

void USelectNumberWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (NumberText)
	{
		NumberText->SetText(FText::AsNumber(Number));
	}
}

void USelectNumberWidget::OnLeftClick()
{
	if (bPlayAnim) { return; }

	bPlayAnim = true;

	// 0~MAXに制限
	--Number;
	Number = Number < 1 ? MaxNumber : Number;


	if (Zoom)
	{
		PlayAnimation(Zoom);
	}
	
}

void USelectNumberWidget::OnRightClick()
{
	if (bPlayAnim) { return; }

	bPlayAnim = true;

	// 0~MAXに制限 
	++Number;
	Number = Number > MaxNumber ? 1 : Number;

	if (Zoom)
	{
		PlayAnimation(Zoom);
	}
}

void USelectNumberWidget::AnimationFinished()
{
	bPlayAnim = false;
	NumberText->SetText(FText::AsNumber(Number));
}

