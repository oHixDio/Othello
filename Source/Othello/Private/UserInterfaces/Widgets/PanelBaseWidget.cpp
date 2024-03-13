// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/PanelBaseWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Border.h"
#include "Components/BackgroundBlur.h"

void UPanelBaseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ParentCanvas = Cast<UCanvasPanel>(GetWidgetFromName("ParentCanvas"));
	
}

void UPanelBaseWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (ParentCanvas == nullptr) { return; }

	if (PanelType == EPanelType::BORDER)
	{
		if (BackgroundBlur)
		{
			BackgroundBlur->RemoveFromParent();
			BackgroundBlur = nullptr;
		}

		if (!Border)
		{
			Border = NewObject<UBorder>(UBorder::StaticClass());
			UCanvasPanelSlot* CPS = ParentCanvas->AddChildToCanvas(Border);
			CPS->SetAnchors(FAnchors(0, 0, 1, 1));
			CPS->SetOffsets(FMargin());
			Border->HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;
			Border->VerticalAlignment = EVerticalAlignment::VAlign_Fill;
		}

		Border->SetBrushColor(FLinearColor(BorderColor));

	}
	else
	{
		if (Border)
		{
			Border->RemoveFromParent();
			Border = nullptr;
		}

		if (!BackgroundBlur)
		{
			BackgroundBlur = NewObject<UBackgroundBlur>(UBackgroundBlur::StaticClass());
			UCanvasPanelSlot* CPS = ParentCanvas->AddChildToCanvas(BackgroundBlur);
			CPS->SetAnchors(FAnchors(0, 0, 1, 1));
			CPS->SetOffsets(FMargin());
			BackgroundBlur->HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;
			BackgroundBlur->VerticalAlignment = EVerticalAlignment::VAlign_Fill;
		}

		BackgroundBlur->SetBlurStrength(BlurStrenge);
	}
}
