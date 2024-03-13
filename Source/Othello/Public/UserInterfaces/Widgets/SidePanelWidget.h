// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SidePanelWidget.generated.h"


class UButton;
class UWidgetAnimation;

/**
 * 
 */
UCLASS()
class OTHELLO_API USidePanelWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

public:
	FORCEINLINE UButton* GetBackButton() const { return BackButton; };

	void Show();

	void Hide();

protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* BackButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim), Category = "Widget | Animation")
	UWidgetAnimation* Slide = nullptr;

	// true‚ÅON
	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bIsClicked = false;

	// true‚ÅAnimation’†
	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bPlayAnim = false;

	UFUNCTION()
	void OnClick();

	UFUNCTION()
	void AnimationFinished();

};
