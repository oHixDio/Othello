// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PanelBaseWidget.generated.h"

class UBorder;
class UBackgroundBlur;
class UCanvasPanel;

UENUM(BlueprintType)
enum class EPanelType : uint8
{
	BORDER UMETA(DisplayName = "BORDER"),
	BLUR UMETA(DisplayName = "BLUR"),
};


UCLASS(ABSTRACT)
class OTHELLO_API UPanelBaseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget),  Category = "Wdiget | Parent")
	UCanvasPanel* ParentCanvas = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Wdiget | Child")
	UBorder* Border = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Wdiget | Child")
	UBackgroundBlur* BackgroundBlur = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wdiget | Asset")
	EPanelType PanelType = EPanelType::BORDER;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wdiget | Asset")
	FColor BorderColor = FColor::Black;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wdiget | Asset")
	float BlurStrenge = 0.0f;

	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;
};
