// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectNumberWidget.generated.h"

class UButton;
class UTextBlock;
class UWidgetAnimation;


/**
 * 
 */
UCLASS()
class OTHELLO_API USelectNumberWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE UButton* GetLeftButton() const { return LeftButton; };
	FORCEINLINE UButton* GetRightButton() const { return RightButton; };
	FORCEINLINE int32 GetNumber() const { return Number; };
	FORCEINLINE void SetMaxNumver(const int32 NewMax) { MaxNumber = NewMax; };

protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* LeftButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UButton* RightButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget | Widget")
	UTextBlock* NumberText = nullptr;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim), Category = "Widget | Animation")
	UWidgetAnimation* Zoom = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	int32 Number = 1;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	int32 MaxNumber = 99;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bPlayAnim = false;
	
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	UFUNCTION()
	void OnLeftClick();

	UFUNCTION()
	void OnRightClick();

	UFUNCTION()
	void AnimationFinished();

};
