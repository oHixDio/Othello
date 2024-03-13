// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/MainWidgets/OthelloMainWidget.h"
#include "UserInterfaces/Widgets/ItemButtonWidget.h"
#include "HUDs/MyHUD.h"

#include "Components/Button.h"

void UOthelloMainWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// Clickイベントに関数をバインド
	if (BackButton)
	{
		BackButton->GetItemButton()->OnClicked.AddDynamic(this, &UOthelloMainWidget::OnBackButtonClick);
	}

	if (PlayButton)
	{
		PlayButton->GetItemButton()->OnClicked.AddDynamic(this, &UOthelloMainWidget::OnPlayButtonClick);
	}

	EndDelegate.BindDynamic(this, &UOthelloMainWidget::AnimationFinished);

	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(Fade, EndDelegate);
	}
}

void UOthelloMainWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UOthelloMainWidget::AnimationFinished()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UOthelloMainWidget::OnPlayButtonClick()
{
	if (Fade)
	{
		PlayAnimationForward(Fade);
	}
}

void UOthelloMainWidget::OnBackButtonClick()
{
	if (AMyHUD* MyHUD = GetOwningPlayer()->GetHUD<AMyHUD>())
	{
		MyHUD->FadeOut(GameSelectLevel);
	}
}
