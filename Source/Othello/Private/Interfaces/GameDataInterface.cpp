// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/GameDataInterface.h"

// Add default functionality here for any IGameDataInterface functions that are not pure virtual.

const FGameData& IGameDataInterface::GetGameData(const FName GameName)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	FGameData* GameData = nullptr;
	return *GameData;
}

void IGameDataInterface::UpdateGameData(const FGameData& GameData)
{
}

const FGameData& IGameDataInterface::CreateGameData(const FName NewGameDataName)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	FGameData* GameData = nullptr;
	return *GameData;
}

