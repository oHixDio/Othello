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


	// Player�l��Mode�����߂�
	////////////////////////////////
public:
	void DecideNumOfPlayerMode();
protected:
	//==============================

	// Player�l��Mode�����߂�
	////////////////////////////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameSelect | Data")
	TSoftObjectPtr<UWorld> TitleLevel;
	//==============================
	


	// Game���I��������@�\
	////////////////////////////////
public:
	void ExitGame(APlayerController* PlayerController);
	//==============================
};
