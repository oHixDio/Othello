// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDs/MyHUD.h"
#include "OthelloHUD.generated.h"

class UOthelloMainWidget;


/**
 * 
 */
UCLASS()
class OTHELLO_API AOthelloHUD : public AMyHUD
{
	GENERATED_BODY()

public:
	AOthelloHUD();

protected:
	UPROPERTY(EditAnywhere, Category = "HUD | Widget")
	UOthelloMainWidget* MainWidget;

	UPROPERTY(EditAnywhere, Category = "HUD | Asset")
	TSubclassOf<UOthelloMainWidget> MainWidgetClass;

	void BeginPlay() override;
};
