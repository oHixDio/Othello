// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Data/GameData.h>


#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameDataInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameDataInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OTHELLO_API IGameDataInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual const FGameData& GetGameData(const FName GameName);
	virtual void UpdateGameData(const FGameData& GameData);
	virtual const FGameData& CreateGameData(const FName NewGameDataName);
};
