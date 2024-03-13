// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScreenCursorWidget.generated.h"

class UImage;
class UCanvasPanelSlot;

/**
 * 
 */
UCLASS()
class OTHELLO_API UScreenCursorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Move(const FVector2D ScreenPosition);

	virtual void NativeConstruct() override;

	FORCEINLINE UCanvasPanelSlot* GetCanpasPanelSlot() const { return CanvasPanelSlot; }

	void SetShowScreenCursor(bool bShow);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Widget |Screen")
	UImage* ScreenCursor;

	UCanvasPanelSlot* CanvasPanelSlot;

	bool bShowScreenCursor = false;

	virtual void NativeOnInitialized() override;
};
