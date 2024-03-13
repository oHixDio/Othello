// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/MainWidgets/GameSelectMainWidget.h"

#include "HUDs/MyHUD.h"
#include "UserInterfaces/Widgets/ItemButtonWidget.h"
#include "UserInterfaces/Widgets/SelectNumberWidget.h"
#include "UserInterfaces/Widgets/MainTextBaseWidget.h"
#include "Kismet/GameplayStatics.h"

#include "Components/Button.h"

void UGameSelectMainWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	// Clickイベントに関数をバインド
	if (BackToTitleButton)
	{
		BackToTitleButton->GetItemButton()->OnClicked.AddDynamic(this, &UGameSelectMainWidget::OnBackToTitlleClick);
	}

	if (PlayButton)
	{
		PlayButton->GetItemButton()->OnClicked.AddDynamic(this, &UGameSelectMainWidget::OpenGame);
	}

	if (GameNumber)
	{
		GameNumber->GetLeftButton()->OnClicked.AddDynamic(this, &UGameSelectMainWidget::UpdateGameList);
		GameNumber->GetRightButton()->OnClicked.AddDynamic(this, &UGameSelectMainWidget::UpdateGameList);
		GameNumber->SetMaxNumver(GameList.Num());
	}

	
}

void UGameSelectMainWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	
}

void UGameSelectMainWidget::OnBackToTitlleClick()
{
	if (AMyHUD* MyHUD = GetOwningPlayer()->GetHUD<AMyHUD>())
	{
		MyHUD->FadeOut(TitleLevel);
	}
}

void UGameSelectMainWidget::UpdateGameList()
{
	int32 CurrentNumber = GameNumber->GetNumber() - 1; UE_LOG(LogTemp, Warning, TEXT("Hi"));

	GameNameText->SetText(GameList[CurrentNumber].GameName);
}

void UGameSelectMainWidget::OpenGame()
{
	if (AMyHUD* MyHUD = GetOwningPlayer()->GetHUD<AMyHUD>())
	{
		int32 CurrentNumber = GameNumber->GetNumber() - 1; UE_LOG(LogTemp, Warning, TEXT("Hi"));

		const auto& Level = GameList[CurrentNumber].LoadWorld;

		MyHUD->FadeOut(Level);
	}
}
