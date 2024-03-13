// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h" 

#include <Data/OthelloPieceColor.h>
#include "InputActionValue.h"

#include "OthelloPlayerController.generated.h"


class UInputMappingContext;
class UInputAction;
class UOthelloPlayerComponent;

USTRUCT()
struct FOthelloPlayerInfoData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	EOthelloPieceColor PlaceColor;

	UPROPERTY()
	bool bIsTurn;

	FOthelloPlayerInfoData() : 
		PlaceColor(EOthelloPieceColor::BLACK),
		bIsTurn(false)
	{};

};


UCLASS()
class OTHELLO_API AOthelloPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	//====================================================================================================================================================================================
	// Field
	//====================================================================================================================================================================================


	//====================================================================================================================================================================================
	// Function
	//====================================================================================================================================================================================
	AOthelloPlayerController();
	virtual void Tick(float DeltaTime) override;

	FText GetGameTextOfGameMode() const;

	void SemiEnabled();
	void Enabled();
	void Disabled();

	FORCEINLINE const FOthelloPlayerInfoData& GetPlayerInfo() const { return PlayerInfo; };
	void SetPlaceColor(EOthelloPieceColor NewColor){ PlayerInfo.PlaceColor = NewColor; };

protected:
	//====================================================================================================================================================================================
	// Field
	//====================================================================================================================================================================================

	// Assets
	//==================================================
	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputMappingContext* OthelloMappingContext;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* ClickAction;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* ScreenCursorMoveAction;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* MouseSlideAction;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* DebugAction1;

	UPROPERTY(EditAnywhere, Category = "Player | Input")
	UInputAction* DebugAction2;
	

	// KeepActors
	//==================================================
	UPROPERTY(VisibleAnywhere, Category = "Player | Actor")
	AActor* FixedCamera;

	UPROPERTY(VisibleAnywhere, Category = "Player | Actor")
	AActor* ClickedActor;

	// Model
	UPROPERTY(VisibleAnywhere, Category = "Player | Actor")
	class AOthelloGameModeBase* GameMode;
	
	// View
	UPROPERTY(VisibleAnywhere, Category = "Player | Actor")
	class AOthelloHUD* HUD;

	// Data
	//==================================================
	UPROPERTY(EditAnywhere, Category = "Player | Data")
	uint32 MouseSpeed = 10;

	UPROPERTY()
	FOthelloPlayerInfoData PlayerInfo;


	//====================================================================================================================================================================================
	// Function
	//====================================================================================================================================================================================
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	// Bind functions
	//==================================================
	void OnBeginClick(const FInputActionValue& Value);
	void OnClick(const FInputActionValue& Value);
	void OnEndClick(const FInputActionValue& Value);

	void OnDebugAction1(const FInputActionValue& Value);
	void OnDebugAction2(const FInputActionValue& Value);
	
};
