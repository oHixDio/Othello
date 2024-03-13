// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameTitleWidget.generated.h"


class UBorder;
class UTextBlock;
/**
 * 
 */
UCLASS()
class OTHELLO_API UGameTitleWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateWidget(const FText TitleText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Widget | Fade")
	void FadeOut();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget")
	UBorder* BackGroundPanel;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget")
	UTextBlock* GameTitleText;

	virtual void NativeOnInitialized() override;
};
