// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Interfaces/GameStateInterface.h>
#include <Data/OthelloPieceColor.h>
#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "OthelloGameStateBase.generated.h"

class AOthelloSquare;
class AOthelloPiece;
class AOthelloPlayerController;
class OthelloGameModeBase;
class UPopupTextWidget;

	//////////////////////////////////////////////////////////////////////////////////////////
	// ゲーム進行中、値が変動するデータを格納
	//////////////////////////////////////////////////////////////////////////////////////////

UCLASS()
class OTHELLO_API AOthelloGameStateBase : public AGameStateBase, public IGameStateInterface
{
	GENERATED_BODY()

public:
	AOthelloGameStateBase();
	virtual void ChangeState(EOthelloState NewState) override;
	virtual void EntryState(EOthelloState CurrentState) override;
	virtual void ExitState(EOthelloState CurrentState) override;
	EOthelloState State = EOthelloState::READY;
	FORCEINLINE EOthelloState GetState() const { return State; }
protected:
	
	virtual void BeginPlay() override;
};
