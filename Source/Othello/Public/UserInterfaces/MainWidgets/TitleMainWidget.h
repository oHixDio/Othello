// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleMainWidget.generated.h"

class UItemButtonWidget;

UCLASS()
class OTHELLO_API UTitleMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

public:
	int32 ChangeSelectButton(int32 Value);

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Widget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* EntryButton;

	UPROPERTY(BlueprintReadWrite, Category = "Widget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* SettingButton;

	UPROPERTY(BlueprintReadWrite, Category = "Widget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* CreditButton;

	UPROPERTY(BlueprintReadWrite, Category = "Widget | Bind Widget", meta = (BindWidget))
	UItemButtonWidget* ExitButton;

	UPROPERTY(VisibleAnywhere)
	int32 SelectButtonIndex = 0;

	UPROPERTY(VisibleAnywhere)
	TArray<UItemButtonWidget*> ButtonList;



};
