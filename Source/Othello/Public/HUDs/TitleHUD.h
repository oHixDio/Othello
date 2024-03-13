// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDs/MyHUD.h"
#include "TitleHUD.generated.h"

class UTitleMainWidget;
class USettingSideWidget;
class UCreditSideWidget;
class UPlaySettingSideWidget;

/**
 * 
 */
UCLASS()
class OTHELLO_API ATitleHUD : public AMyHUD
{
	GENERATED_BODY()

public:
	

	ATitleHUD();

	FORCEINLINE UTitleMainWidget* GetTitleWidget() { return TitleMainWidget; };

protected:
	UPROPERTY(EditAnywhere, Category = "HUD | MainWidget")
	UTitleMainWidget* TitleMainWidget;

	UPROPERTY(EditAnywhere, Category = "HUD | SideWidget")
	UPlaySettingSideWidget* PlaysettingSideWidget;

	UPROPERTY(EditAnywhere, Category = "HUD | SideWidget")
	USettingSideWidget* SettingSideWidget;

	UPROPERTY(EditAnywhere, Category = "HUD | SideWidget")
	UCreditSideWidget* CreditSideWidget;

	UPROPERTY(EditAnywhere, Category = "HUD | Asset")
	TSubclassOf<UTitleMainWidget> TitleMainWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD | Asset")
	TSubclassOf<UPlaySettingSideWidget> PlaySettingSideWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD | Asset")
	TSubclassOf<USettingSideWidget> SettingSideWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD | Asset")
	TSubclassOf<UCreditSideWidget> CreditSideWidgetClass;

	void BeginPlay() override;

	
};
