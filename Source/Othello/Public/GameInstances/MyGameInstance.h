// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Data/GameData.h>
#include <Interfaces/GameDataInterface.h>
#include <Data/OthelloPieceColor.h>

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class OTHELLO_API UMyGameInstance : public UGameInstance, public IGameDataInterface
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	////////////////////////////////
	// Player�̐l�����i�[����
public:
	void SetNumOfPlayerMode(const ENumOfPlayerMode Mode);
	const ENumOfPlayerMode GetNumOfPlayerMode() const { return NumOfPlayerMode; };

protected:
	UPROPERTY(EditAnywhere, Category = "GameInstance | Player")
	ENumOfPlayerMode NumOfPlayerMode;
	//==============================


	////////////////////////////////
	// Game����CPU���܂߂��ő�Player�l�������߂�
public:
	FGameData& SendGameDataByGameName(const FName& Name);

protected:
	UPROPERTY(EditAnywhere, Category = "GameInstance | Player")
	TArray<FGameData> GameDataList;
	//==============================
};
