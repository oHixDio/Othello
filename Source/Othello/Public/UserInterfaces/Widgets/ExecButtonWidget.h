// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExecButtonWidget.generated.h"

class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class OTHELLO_API UExecButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE UButton* GetExecButton() const { return ExecButton; };

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* ExecButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UTextBlock* ExecText = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FText CurExecText = FText::FromString("Exec");
	
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;
};
