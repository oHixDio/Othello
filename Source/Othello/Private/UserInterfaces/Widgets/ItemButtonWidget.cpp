// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/ItemButtonWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"



void UItemButtonWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ItemButton)
	{
		ItemButton->OnClicked.AddDynamic(this, &UItemButtonWidget::OnClick);
		ItemButton->OnHovered.AddDynamic(this, &UItemButtonWidget::OnHover);
		ItemButton->OnUnhovered.AddDynamic(this, &UItemButtonWidget::OnUnHover);
	}

	EndDelegate.BindDynamic(this, &UItemButtonWidget::AnimationFinished);

	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(Slide, EndDelegate);
	}

	if (ItemText)
	{
		ItemText->SetText(CurItemText);
		ItemText->SetShadowColorAndOpacity(DefaultShadowColor);
	}
	
	if (PlayIcon)
	{
		PlayIcon->SetColorAndOpacity(DefaultPlayIconColor);
	}

	bIsChoise = false;
	bPlayAnim = false;
}

void UItemButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (ItemText)
	{
		ItemText->SetText(CurItemText);
	}
}

void UItemButtonWidget::AnimationFinished()
{
	if (bIsChoise)
	{
		ItemText->SetShadowColorAndOpacity(ChosenShadowColor);
		PlayIcon->SetColorAndOpacity(ChosenPlayIconColor);
	}
	else
	{
		ItemText->SetShadowColorAndOpacity(DefaultShadowColor);
		PlayIcon->SetColorAndOpacity(DefaultPlayIconColor);
	}

	if (ItemButton->IsHovered())
	{
		OnHover();
	}

	bPlayAnim = false;
}

void UItemButtonWidget::OnClick()
{
	if (bPlayAnim) { return; }

	if (Slide)
	{
		bIsChoise ? UnChoise() : Choise();
		bPlayAnim = true;
	}
}

void UItemButtonWidget::OnHover()
{
	if (ItemText && !bIsChoise)
	{
		ItemText->SetShadowColorAndOpacity(HoverShadowColor);
	}
}

void UItemButtonWidget::OnUnHover()
{
	if (ItemText && !bIsChoise)
	{
		ItemText->SetShadowColorAndOpacity(DefaultShadowColor);
	}
}

void UItemButtonWidget::Choise()
{
	PlayAnimationForward(Slide);
	bIsChoise = true;
}

void UItemButtonWidget::UnChoise()
{
	PlayAnimationReverse(Slide);
	bIsChoise = false;
}

void UItemButtonWidget::SetButtonStyle(EButtonStyle NewStyle)
{
	switch (NewStyle)
	{
	case EButtonStyle::NORMAL:
		ItemText->SetShadowColorAndOpacity(DefaultShadowColor);
		break;
	case EButtonStyle::HOVERED:
		ItemText->SetShadowColorAndOpacity(HoverShadowColor);
		break;
	case EButtonStyle::PRESSED:
		ItemText->SetShadowColorAndOpacity(ChosenShadowColor);
		break;
	default:
		break;
	}
}
