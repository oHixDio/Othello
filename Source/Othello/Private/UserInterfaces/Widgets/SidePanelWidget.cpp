// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/SidePanelWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"

void USidePanelWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	bIsClicked = false;
	bPlayAnim = false;

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &USidePanelWidget::OnClick);
	}

	EndDelegate.BindDynamic(this, &USidePanelWidget::AnimationFinished);
	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(Slide, EndDelegate);
	}
}

void USidePanelWidget::OnClick()
{
	if (bPlayAnim) { return; }
	// ON‚È‚çHide
	bIsClicked ? Hide() : Show();

	bIsClicked = !bIsClicked;
}

void USidePanelWidget::AnimationFinished()
{
	// OFF‚Å”ñ•\Ž¦‚É‚·‚é
	if (!bIsClicked)
	{
		SetVisibility(ESlateVisibility::Collapsed);
	}
	bPlayAnim = false;
}

void USidePanelWidget::Show()
{
	SetVisibility(ESlateVisibility::Visible);
	PlayAnimationForward(Slide);
	bPlayAnim = true;
}

void USidePanelWidget::Hide()
{
	PlayAnimationReverse(Slide);
	bPlayAnim = true;
}