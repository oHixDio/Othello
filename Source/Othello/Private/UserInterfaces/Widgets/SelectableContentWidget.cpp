// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/SelectableContentWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void USelectableContentWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	SelectedContentIndex = 0;
	bPlayAnim = false;

	// Clickイベントに関数をバインド
	if (LeftButton)
	{
		LeftButton->OnClicked.AddDynamic(this, &USelectableContentWidget::OnLeftClick);
		LeftButton->OnHovered.AddDynamic(this, &USelectableContentWidget::OnHover);
		LeftButton->OnUnhovered.AddDynamic(this, &USelectableContentWidget::OnUnHover);
	}
	if (RightButton)
	{
		RightButton->OnClicked.AddDynamic(this, &USelectableContentWidget::OnRightClick);
		RightButton->OnHovered.AddDynamic(this, &USelectableContentWidget::OnHover);
		RightButton->OnUnhovered.AddDynamic(this, &USelectableContentWidget::OnUnHover);
	}

	// AnimFinishedイベントに関数をバインド
	EndDelegate.BindDynamic(this, &USelectableContentWidget::AnimationFinished);
	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(Zoom, EndDelegate);
	}
	
}

void USelectableContentWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (ContentText)
	{
		ContentText->SetText(CurContentText);
	}

	if (SelectableText)
	{
		if (!SelectableTextList.IsEmpty())
		{
			if (IsInArrayIndex())
			{
				SelectableText->SetText(SelectableTextList[SelectedContentIndex]);
			}
			else
			{
				SelectedContentIndex = 0;
				SelectableText->SetText(SelectableTextList[SelectedContentIndex]);
			}
		}
	}

}

void USelectableContentWidget::OnLeftClick()
{
	if (bPlayAnim) { return; }

	SelectedContentIndex--;
	SelectedContentIndex = SelectedContentIndex < 0 ? SelectableTextList.Num() - 1 : SelectedContentIndex;

	if (Zoom)
	{
		PlayAnimation(Zoom);
		bPlayAnim = true;
	}
}

void USelectableContentWidget::OnRightClick()
{
	if (bPlayAnim) { return; }

	SelectedContentIndex++;
	SelectedContentIndex = SelectedContentIndex > SelectableTextList.Num() - 1 ? 0 : SelectedContentIndex;

	if (Zoom)
	{
		PlayAnimation(Zoom);
		bPlayAnim = true;
	}
}

void USelectableContentWidget::OnHover()
{
	if (ContentText)
	{
		ContentText->SetShadowColorAndOpacity(HoverShadowColor);
	}
}

void USelectableContentWidget::OnUnHover()
{
	if (ContentText)
	{
		ContentText->SetShadowColorAndOpacity(DefaultShadowColor);
	}
}

void USelectableContentWidget::AnimationFinished()
{
	bPlayAnim = false;
	if (SelectableText && IsInArrayIndex())
	{
		SelectableText->SetText(SelectableTextList[SelectedContentIndex]);
		UE_LOG(LogTemp, Warning, TEXT("Index is %d"), SelectedContentIndex);
		UE_LOG(LogTemp, Warning, TEXT("Num is %d"), SelectableTextList.Num());
	}
}
