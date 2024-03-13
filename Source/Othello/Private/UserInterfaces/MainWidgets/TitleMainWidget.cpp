// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/MainWidgets/TitleMainWidget.h"

#include "UserInterfaces/Widgets/ItemButtonWidget.h"
#include "UserInterfaces/SideWidgets/PlaySettingSideWidget.h"
#include "UserInterfaces/SideWidgets/CreditSideWidget.h"
#include "UserInterfaces/SideWidgets/SettingSideWidget.h"

#include "Components/Button.h"

void UTitleMainWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ButtonList.Add(EntryButton);
	ButtonList.Add(SettingButton);
	ButtonList.Add(CreditButton);
	ButtonList.Add(ExitButton);

	SelectButtonIndex = 0;
}

void UTitleMainWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	
}

int32 UTitleMainWidget::ChangeSelectButton(int32 Value)
{
	// 変更後インデックスをキープ
	int32 ChangedIndex = SelectButtonIndex + Value;
	// Indexの数値を配列に合わせる
	if (ChangedIndex > ButtonList.Num() - 1)
	{
		ChangedIndex = 0;
	}
	else if (ChangedIndex < 0)
	{
		ChangedIndex = ButtonList.Num() - 1;
	}

	SelectButtonIndex = ChangedIndex;

	// 色変更
	for (int32 i = 0; i < ButtonList.Num(); i++)
	{
		ButtonList[i]->SetButtonStyle(EButtonStyle::NORMAL);
		if (i == SelectButtonIndex)
		{
			ButtonList[i]->SetButtonStyle(EButtonStyle::HOVERED);
		}
	}


	return SelectButtonIndex;
}
