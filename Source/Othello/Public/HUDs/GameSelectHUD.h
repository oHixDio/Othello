// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDs/MyHUD.h"
#include "GameSelectHUD.generated.h"

class UGameSelectMainWidget;

/**
 * 
 */
UCLASS()
class OTHELLO_API AGameSelectHUD : public AMyHUD
{
	GENERATED_BODY()

public:
	AGameSelectHUD();

protected:
	UPROPERTY(EditAnywhere, Category = "HUD | Widget")
	UGameSelectMainWidget* GameSelectMainWidget;

	UPROPERTY(EditAnywhere, Category = "HUD | Asset")
	TSubclassOf<UGameSelectMainWidget> GameSelectMainWidgetClass;

	void BeginPlay() override;
	
};
