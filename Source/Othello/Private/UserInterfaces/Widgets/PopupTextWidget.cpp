// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/PopupTextWidget.h"

#include "Components/TextBlock.h"

void UPopupTextWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// AnimFinishedイベントに関数をバインド
	EndDelegate.BindDynamic(this, &UPopupTextWidget::AnimationFinished);
	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(Popup, EndDelegate);
	}
}

void UPopupTextWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (PopupText)
	{
		PopupText->SetText(CurrentPopupText);
	}
	
}

void UPopupTextWidget::AnimationFinished()
{
	Hide();
	bPlayAnim = false;
}

void UPopupTextWidget::Show(const FText Text)
{
	if (bPlayAnim) { return; }
	bPlayAnim = true;

	if (PopupText)
	{
		PopupText->SetText(Text);
		CurrentPopupText = Text;
	}

	if (Popup)
	{
		SetVisibility(ESlateVisibility::Visible);
		PlayAnimationForward(Popup);
	}
}

void UPopupTextWidget::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}
