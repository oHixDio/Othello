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

	// Player����
	{
		// Player����l�ȏ�ł���Ȃ��
		if (OthelloGameData.JoinPlayerNum > 1)
		{
			// �����I�ɐ�������郁�C��Player������̂�1����X�^�[�g
			for (int8 i = 1; i < OthelloGameData.JoinPlayerNum; i++)
			{
				// ����l���𒴂���ꍇ�A�I��
				if (i > OthelloGameData.MAX_PLAYER_NUM)
				{
					break;
				}
				// Player�𐶐�
				// �������������Player��ID��0�ƂȂ�BID�͈��
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

	// CPU�̐l�������肷��(����l��-�Q�����Ă���Player�̐l��)
	OthelloGameData.CPUNum = OthelloGameData.MAX_PLAYER_NUM - PlayerList.Num();

	// Player��Piece�̐F������U��
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


