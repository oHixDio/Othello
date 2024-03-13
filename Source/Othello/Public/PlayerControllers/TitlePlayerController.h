// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputActionValue.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitlePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class OTHELLO_API ATitlePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Assets
	//==================================================
	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputMappingContext* TitleMappingContext;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* DoneAction;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* BackAction;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* SelectableColAction;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* SelectableRowAction;


	ATitlePlayerController();

protected:

	void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void OnSelectCol(const FInputActionValue& Value);
	void OnSelectRow(const FInputActionValue& Value);
	void OnDone(const FInputActionValue& Value);
	void OnBack(const FInputActionValue& Value);
	
};
