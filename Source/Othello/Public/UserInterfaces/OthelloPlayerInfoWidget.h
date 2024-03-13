// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OthelloPlayerInfoWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class OTHELLO_API UOthelloPlayerInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateWidget(const struct FOthelloPlayerData& PlayerData);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Data")
	UTextBlock* NameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Data")
	UTextBlock* ColorText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Data")
	UTextBlock* TurnText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Data")
	UTextBlock* ScoreText;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	int32 Score;

	virtual void NativeConstruct() override;
};
