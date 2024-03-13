// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/OthelloPlayerInfoWidget.h"
#include "Components/OthelloPlayerComponent.h"

#include "Components/TextBlock.h"
#include "Styling/SlateColor.h"


void UOthelloPlayerInfoWidget::NativeConstruct()
{
	Super::NativeConstruct();

	NameText->SetText(FText::FromString(TEXT("Name")));

	ColorText->SetText(FText::FromString(TEXT("Black")));
	ColorText->SetColorAndOpacity(FSlateColor(FColor::Black));

	TurnText->SetText(FText::FromString(TEXT("Your Turn")));

	Score = 0;
	ScoreText->SetText(FText::Format(NSLOCTEXT("UOthelloPlayerInfoWidget", "ScoreText", "Score:{0}"), Score));
}

void UOthelloPlayerInfoWidget::UpdateWidget(const FOthelloPlayerData& PlayerData)
{
	NameText->SetText(FText::FromName(PlayerData.Name));

	switch (PlayerData.Type)
	{
	case EOthelloSquareType::BLACK:
		ColorText->SetText(FText::FromString(TEXT("Black")));
		ColorText->SetColorAndOpacity(FSlateColor(FColor::Black));
		break;
	case EOthelloSquareType::WHITE:
		ColorText->SetText(FText::FromString(TEXT("White")));
		ColorText->SetColorAndOpacity(FSlateColor(FColor::White));
		break;
	default:
		ColorText->SetText(FText::FromString(TEXT("Black")));
		ColorText->SetColorAndOpacity(FSlateColor(FColor::Black));
		break;
	}

	PlayerData.bIsTurn ? TurnText->SetText(FText::FromString(TEXT("Your Turn"))) : TurnText->SetText(FText::FromString(TEXT("Enemy Turn")));

	Score = PlayerData.Score;
	ScoreText->SetText(FText::Format(NSLOCTEXT("UOthelloPlayerInfoWidget", "ScoreText", "Score:{0}"), Score));
}
