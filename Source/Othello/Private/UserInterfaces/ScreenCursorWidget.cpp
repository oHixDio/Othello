// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/ScreenCursorWidget.h"

#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/PanelWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"


void UScreenCursorWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


void UScreenCursorWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CanvasPanelSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(ScreenCursor);

	ScreenCursor->SetVisibility(ESlateVisibility::Collapsed);
}

void UScreenCursorWidget::Move(const FVector2D ScreenPosition)
{
}

void UScreenCursorWidget::SetShowScreenCursor(bool bShow)
{
	bShowScreenCursor = bShow;
	ScreenCursor->SetVisibility(bShowScreenCursor ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}