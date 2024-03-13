// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Data/OthelloSquareType.h>
#include "OthelloPlayerComponent.generated.h"

USTRUCT()
struct FOthelloPlayerData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Player Data")
	FName Name;

	UPROPERTY(EditAnywhere, Category = "Player Data")
	EOthelloSquareType Type;

	UPROPERTY(EditAnywhere, Category = "Player Data")
	bool bIsTurn;

	UPROPERTY(EditAnywhere, Category = "Player Data")
	uint32 Score;

	UPROPERTY(EditAnywhere, Category = "Player Data")
	uint32 MyTypeAmount;

	UPROPERTY(EditAnywhere, Category = "Player Data")
	uint32 MyReverseAmount;

	FOthelloPlayerData() :
		Name("Default"),
		Type(EOthelloSquareType::BLACK),
		bIsTurn(false),
		Score(0),
		MyTypeAmount(0),
		MyReverseAmount(0)
	{
	};

	void InitNumericData()
	{
		Score = 0;
		MyTypeAmount = 0;
		MyReverseAmount = 0;
	};
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OTHELLO_API UOthelloPlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOthelloPlayerComponent();

	FORCEINLINE const FOthelloPlayerData& GetPlayerData() const { return PlayerData; }
	FORCEINLINE const FName GetPlayerName() const { return PlayerData.Name; }
	FORCEINLINE const EOthelloSquareType GetPlayerType() const { return PlayerData.Type; }
	FORCEINLINE const bool IsYourTurn() const { return PlayerData.bIsTurn; }
	FORCEINLINE const uint32 GetPlayerScore() const { return PlayerData.Score; }

	void SetPlayerName(const FName NewName);
	void SetPlayerType(const EOthelloSquareType NewType);
	void SetIsTurn(const bool bIsTurn);
	void SetScore(const uint32 NewScore);
	void SetMyTypeAmount(const uint32 NewAmount);
	void SetReverseAmount(const uint32 NewAmount);

protected:
	UPROPERTY(EditAnywhere, Category = "OthelloPlayer | Data")
	FOthelloPlayerData PlayerData;
};
