// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameSelectMainWidget.generated.h"

class UItemButtonWidget;
class USelectNumberWidget;
class UMainTextBaseWidget;

USTRUCT()
struct FGameSelect
{
	GENERATED_USTRUCT_BODY()

	FGameSelect() {};

	UPROPERTY(EditAnywhere, Category = "GameList || Data")
	FText GameName = FText();

	UPROPERTY(EditAnywhere, Category = "GameList || Data")
	TSoftObjectPtr<UWorld> LoadWorld;
};

/**
 * 
 */
UCLASS()
class OTHELLO_API UGameSelectMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Wdiget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* PlayButton;

	UPROPERTY(BlueprintReadWrite, Category = "Wdiget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* BackToTitleButton;

	UPROPERTY(BlueprintReadWrite, Category = "Wdiget | Bind Widget", meta = (BindWidget))
	UMainTextBaseWidget* GameNameText;

	UPROPERTY(BlueprintReadWrite, Category = "Wdiget | Bind Widget", meta = (BindWidget))
	USelectNumberWidget* GameNumber;

protected:
	UPROPERTY(EditAnywhere, Category = "GameSelect | Data")
	TArray<FGameSelect> GameList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameSelect | Data")
	TSoftObjectPtr<UWorld> TitleLevel;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void OnBackToTitlleClick();

	UFUNCTION()
	void UpdateGameList();

	UFUNCTION()
	void OpenGame();
};
