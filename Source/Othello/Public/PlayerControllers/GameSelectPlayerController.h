// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameSelectPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OTHELLO_API AGameSelectPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGameSelectPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
