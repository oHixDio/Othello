// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class UFadeWidget;

/**
 * 
 */
UCLASS()
class OTHELLO_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMyHUD();
	
	void FadeIn();

	void FadeOut(TSoftObjectPtr<UWorld> Level = nullptr);

	FORCEINLINE UFadeWidget* GetFadeWidget() const { return FadeWidget; };
protected:

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Widget | Widget")
	UFadeWidget* FadeWidget;

	UPROPERTY(EditAnywhere, Category = "Widget | Asset")
	TSubclassOf<UFadeWidget> FadeWidgetClass;

};
