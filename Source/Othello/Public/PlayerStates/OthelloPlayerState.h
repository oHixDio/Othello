// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include <Data/OthelloSquareType.h>
#include "OthelloPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class OTHELLO_API AOthelloPlayerState : public APlayerState
{
	GENERATED_BODY()
	

public:
	AOthelloPlayerState();

protected:
	virtual void BeginPlay() override;
};
