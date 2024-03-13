// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableContentWidget.generated.h"

class UButton;
class UTextBlock;
class UWidgetAnimation;

/**
 * 
 */
UCLASS()
class OTHELLO_API USelectableContentWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE UButton* GetLeftButton() const { return LeftButton; };
	FORCEINLINE UButton* GetRightButton() const { return RightButton; };

	FORCEINLINE int32 GetSelectedContentIndex() const { return SelectedContentIndex; };

protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* LeftButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* RightButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UTextBlock* ContentText = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UTextBlock* SelectableText = nullptr;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim), Category = "Widget | Animation")
	UWidgetAnimation* Zoom = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FText CurContentText = FText::FromString("Content");

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	TArray<FText> SelectableTextList;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	int32 SelectedContentIndex;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor DefaultShadowColor = FColor();

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor ChosenShadowColor = FColor();

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FColor HoverShadowColor = FColor();

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bPlayAnim = false;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void OnLeftClick();

	UFUNCTION()
	void OnRightClick();

	UFUNCTION()
	void OnHover();

	UFUNCTION()
	void OnUnHover();

	UFUNCTION()
	void AnimationFinished();

	FORCEINLINE bool IsInArrayIndex() const { return SelectableTextList.Num() > SelectedContentIndex && SelectedContentIndex >= 0; };
};
