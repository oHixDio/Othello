// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::SetNumOfPlayerMode(const ENumOfPlayerMode Mode)
{
	NumOfPlayerMode = Mode;
}

////////////////////////////////
// GameñàÇÃCPUÇä‹ÇﬂÇΩç≈ëÂPlayerêlêîÇåàÇﬂÇÈ

FGameData& UMyGameInstance::SendGameDataByGameName(const FName& Name)
{
	for (FGameData& GameData: GameDataList)
	{
		if (GameData.GameName.IsEqual(Name))
		{
			UE_LOG(LogTemp, Log, TEXT("Returns the appropriate game data matching the name."));
			return GameData;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("No game data matching the name was found."));
	return GameDataList[0];
}

//==============================