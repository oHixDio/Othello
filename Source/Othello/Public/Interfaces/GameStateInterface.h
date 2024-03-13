// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameStateInterface.generated.h"

UENUM()
enum class EOthelloState
{
	READY UMETA(DisplayName = "READY"),
	PLAY UMETA(DisplayName = "PLAY"),
	RESULT UMETA(DisplayName = "RESULT"),
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OTHELLO_API IGameStateInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ChangeState(EOthelloState NewState);
	virtual void EntryState(EOthelloState CurrentState);
	virtual void ExitState(EOthelloState CurrentState);
};
