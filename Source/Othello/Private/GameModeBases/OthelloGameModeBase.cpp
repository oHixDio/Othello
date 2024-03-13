// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameModeBases/OthelloGameModeBase.h"
#include "PlayerControllers/OthelloPlayerController.h"
#include "GameStateBases/OthelloGameStateBase.h"
#include "Components/OthelloSystemComponent.h"
#include "Actors/OthelloSquare.h"
#include "Actors/OthelloPiece.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

AOthelloGameModeBase::AOthelloGameModeBase()
{
	OthelloSystemComponent = CreateDefaultSubobject<UOthelloSystemComponent>("Othello System");
}

void AOthelloGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("----- Create -----"));

	// Player生成
	{
		// Playerが一人以上であるならば
		if (OthelloGameData.JoinPlayerNum > 1)
		{
			// 自動的に生成されるメインPlayerがいるので1からスタート
			for (int8 i = 1; i < OthelloGameData.JoinPlayerNum; i++)
			{
				// 上限人数を超える場合、終了
				if (i > OthelloGameData.MAX_PLAYER_NUM)
				{
					break;
				}
				// Playerを生成
				// 自動生成されるPlayerのIDは0となる。IDは一意
				UGameplayStatics::CreatePlayer(GetWorld(), i);
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("Clreate player num is %d"), PlayerList.Num());
	}
}

void AOthelloGameModeBase::JoinPlayer(AOthelloPlayerController* OthelloPlayer)
{
	PlayerList.Add(OthelloPlayer);
}

void AOthelloGameModeBase::Start()
{
	UE_LOG(LogTemp, Warning, TEXT("----- Start -----"));

	UE_LOG(LogTemp, Warning, TEXT("----- Init -----"));

	// CPUの人数を決定する(上限人数-参加しているPlayerの人数)
	OthelloGameData.CPUNum = OthelloGameData.MAX_PLAYER_NUM - PlayerList.Num();

	// PlayerのPieceの色を割り振る
	for (int i = 0; i < PlayerList.Num(); i++)
	{
		PlayerList[i]->SetPlaceColor(OthelloGameData.GetPlayer2Color());
	}
	PlayerList[0]->SetPlaceColor(OthelloGameData.Player1Color);

	UE_LOG(LogTemp, Warning, TEXT("spu num is %d"), OthelloGameData.CPUNum);
}

void AOthelloGameModeBase::Placement(AActor* Target)
{
	if (AOthelloSquare* Square = Cast<AOthelloSquare>(Target))
	{
		OthelloSystem()->Placement(Square);
	}
}


