// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <Data/GameData.h>
#include <Data/OthelloPieceColor.h>
#include <Data/OthelloSquareType.h>

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OthelloGameModeBase.generated.h"

class UOthelloSystemComponent;
class AOthelloGameStateBase;
class AOthelloPlayerController;
class UOthelloPlayerComponent;
class USoundBase;
class AOthelloSquare;
class AOthelloPiece;

USTRUCT()
struct FOthelloGameData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "OthelloGameData")
	EOthelloPieceColor Player1Color;

	UPROPERTY(EditAnywhere, Category = "OthelloGameData")
	EOthelloPieceColor FirstPlayerColor;

	UPROPERTY(VisibleAnywhere, Category = "Othello | Data")
	uint8 MAX_PLAYER_NUM;

	UPROPERTY(EditAnywhere, Category = "Othello | Data")
	uint8 JoinPlayerNum;

	UPROPERTY(VisibleAnywhere, Category = "Othello | Data")
	uint8 CPUNum;

	FOthelloGameData() :
		Player1Color(EOthelloPieceColor::BLACK),
		FirstPlayerColor(EOthelloPieceColor::BLACK),
		MAX_PLAYER_NUM(2),
		JoinPlayerNum(1),
		CPUNum(1)
	{
	};

	EOthelloPieceColor GetPlayer2Color() const
	{
		return Player1Color == EOthelloPieceColor::BLACK ? EOthelloPieceColor::WHITE : EOthelloPieceColor::BLACK;
	};
};



/**
 * 
 */
UCLASS()
class OTHELLO_API AOthelloGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	AOthelloGameModeBase();
	virtual void BeginPlay() override;
protected:
	// KeepActors
	//==================================================
	UPROPERTY(VisibleAnywhere, Category = "GameMode | Actor")
	AOthelloGameStateBase* MyGameState;

	// Assets
	//==================================================
	UPROPERTY(EditAnywhere, Category = "GameMode | Asset")
	USoundBase* MainBGM;

	// Data
	//==================================================

	UPROPERTY(EditAnywhere, Category = "GameMode | Data")
	float GameStartDelay = 3.5f;

	UPROPERTY(VisibleAnywhere, Category = "GameMode | Data")
	bool bIsMultiPlaying = false;

	FTimerHandle GameStartTimerHandle;
	


	//========================================================================================
	// GameData
	//========================================================================================
public:
	FORCEINLINE FName GetGameName()const { return GameData.GameName; }
protected:
	UPROPERTY(EditAnywhere, Category = "GameMode | Data")
	FGameData GameData; // UGameDataBaseと変更予定

	//========================================================================================
	// Gameの進行を進める機能。
	//========================================================================================
public:
	// Othelloを開始する。
	virtual void Start();

	

	//========================================================================================
	// Othelloの機能
	//========================================================================================
public:
	FORCEINLINE const UOthelloSystemComponent* GetOthelloSystem() const { return OthelloSystemComponent; };

	void Placement(AActor* Target);
protected:
	UPROPERTY(EditAnywhere, Category = "GameMode | Component")
	UOthelloSystemComponent* OthelloSystemComponent;

	UPROPERTY(EditAnywhere, Category = "GameMode | Data")
	FOthelloGameData OthelloGameData;

	UPROPERTY()
	float TurnInterval = 3.0f;

	UPROPERTY()
	FTimerHandle TurnIntervalTimerHandle;

	UPROPERTY()
	float CPUPlacementTime = 3.0f;

	UPROPERTY()
	FTimerHandle CPUPlacementTimerHandle;

	FORCEINLINE UOthelloSystemComponent* OthelloSystem() { return OthelloSystemComponent; };



	//========================================================================================
	// JoinPlayerを管理するデータ群
	//========================================================================================
public:
	void JoinPlayer(AOthelloPlayerController* OthelloPlayer);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Othello | Actor")
	TArray<AOthelloPlayerController*> PlayerList;
};
