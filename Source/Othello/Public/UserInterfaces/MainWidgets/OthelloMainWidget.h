// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OthelloMainWidget.generated.h"

class UItemButtonWidget;

/**
 * 
 */
UCLASS()
class OTHELLO_API UOthelloMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(BlueprintReadWrite, Category = "Wdiget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* PlayButton;

	UPROPERTY(BlueprintReadWrite, Category = "Wdiget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* BackButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameSelect | Data")
	TSoftObjectPtr<UWorld> GameSelectLevel;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* Fade;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void AnimationFinished();

	UFUNCTION()
	void OnPlayButtonClick();

	UFUNCTION()
	void OnBackButtonClick();
};
