// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FadeWidget.generated.h"

class UBorder;
/**
 * 
 */
UCLASS()
class OTHELLO_API UFadeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void FadeIn();

	void FadeOut(TSoftObjectPtr<UWorld> Level = nullptr);

	FORCEINLINE UWidgetAnimation* GetFadeAnimation() const { return FadeAnimation; };

protected:
	UPROPERTY()
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget")
	UBorder* FadePanel;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* FadeAnimation;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	bool bShowViewPort = false;

	UPROPERTY(VisibleAnywhere, Category = "Widget | Data")
	TSoftObjectPtr<UWorld> LoadLevel;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void AnimationFinished();
};
