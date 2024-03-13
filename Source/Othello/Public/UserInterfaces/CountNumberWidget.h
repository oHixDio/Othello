// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CountNumberWidget.generated.h"


class UTextBlock;
/**
 * 
 */
UCLASS()
class OTHELLO_API UCountNumberWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE int64 GetNumber() const { return Number; };
	void SetNumber(const int64 NewNumber);

	void IncrementNumber();
	void DecrementNumber();
	void CountUp(int64 TargetNumber);
	void CountDown(int64 TargetNumber);

	void UpdateWidget();
protected:
	void NativeConstruct() override;
	void NativeOnInitialized() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Content")
	UTextBlock* NumberText;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	int64 Number;
	
	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	int64 MaxNumber;
};
