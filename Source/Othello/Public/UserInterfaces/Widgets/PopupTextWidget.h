// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopupTextWidget.generated.h"

class UWidgetAnimation;
class UTextBlock;

/**
 * 
 */
UCLASS(ABSTRACT)
class OTHELLO_API UPopupTextWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Show(const FText Text);

	void Hide();
protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UTextBlock* PopupText = nullptr;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim), Category = "Widget | Animation")
	UWidgetAnimation* Popup = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget | Data")
	FText CurrentPopupText = FText::FromString("Popup");

	UPROPERTY()
	bool bPlayAnim = false;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void AnimationFinished();
};
