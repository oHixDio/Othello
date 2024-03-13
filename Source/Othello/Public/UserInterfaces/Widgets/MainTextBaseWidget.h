// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainTextBaseWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS(ABSTRACT)
class OTHELLO_API UMainTextBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetText(const FText NewText);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Wdiget | Widget")
	UTextBlock* MainText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wdiget | Asset")
	FText NewMainText;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	
};
