// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemButtonWidget.generated.h"


class UWidgetAnimation;
class UButton;
class UTextBlock;
class UImage;

UENUM()
enum class EButtonStyle :uint8
{
	NORMAL,
	HOVERED,
	PRESSED,
};

/**
 * 
 */
UCLASS()
class OTHELLO_API UItemButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE UButton* GetItemButton() const { return ItemButton; };

	UFUNCTION()
	void Choise();

	UFUNCTION()
	void UnChoise();

	void SetButtonStyle(EButtonStyle NewStyle);

protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* ItemButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UTextBlock* ItemText = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UImage* PlayIcon = nullptr;
	
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* Slide = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FText CurItemText = FText::FromString("Item");

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor DefaultShadowColor = FColor();

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor HoverShadowColor = FColor();

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor ChosenShadowColor = FColor();

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor DefaultPlayIconColor = FColor();

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor ChosenPlayIconColor = FColor();

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bIsChoise = false;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bPlayAnim = false;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void OnClick();

	UFUNCTION()
	void AnimationFinished();

	UFUNCTION()
	void OnHover();

	UFUNCTION()
	void OnUnHover();
};
