// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "TitleGameModeBase.generated.h"


/**
 * 
 */
UCLASS(ABSTRACT)
class OTHELLO_API ATitleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATitleGameModeBase();
	virtual void BeginPlay() override;


	// Player人数Modeを決める
	////////////////////////////////
public:
	void DecideNumOfPlayerMode();
protected:
	//==============================

	// Player人数Modeを決める
	////////////////////////////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameSelect | Data")
	TSoftObjectPtr<UWorld> TitleLevel;
	//==============================
	


	// Gameを終了させる機能
	////////////////////////////////
public:
	void ExitGame(APlayerController* PlayerController);
	//==============================
};
