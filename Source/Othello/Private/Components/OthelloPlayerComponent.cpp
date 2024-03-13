// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/OthelloPlayerComponent.h"

UOthelloPlayerComponent::UOthelloPlayerComponent()
{
}

void UOthelloPlayerComponent::SetPlayerName(const FName NewName)
{
	PlayerData.Name = NewName;
}

void UOthelloPlayerComponent::SetPlayerType(EOthelloSquareType NewType)
{
	PlayerData.Type = NewType;
}

void UOthelloPlayerComponent::SetIsTurn(const bool bIsTurn)
{
	PlayerData.bIsTurn = bIsTurn;
}

void UOthelloPlayerComponent::SetScore(const uint32 NewScore)
{
	PlayerData.Score = NewScore;
}

void UOthelloPlayerComponent::SetMyTypeAmount(const uint32 NewAmount)
{
	PlayerData.MyTypeAmount = NewAmount;
}

void UOthelloPlayerComponent::SetReverseAmount(const uint32 NewAmount)
{
	PlayerData.MyReverseAmount = NewAmount;
}
