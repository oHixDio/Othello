// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlaySettingSideWidget.generated.h"

class USelectableContentWidget;
class UExecButtonWidget;

UCLASS()
class OTHELLO_API UPlaySettingSideWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

protected:

	// UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	// UExecButtonWidget* PlayButton;

	// UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	// USelectableContentWidget* NumOfPlayerContent;
};
