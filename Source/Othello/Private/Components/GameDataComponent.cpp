// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GameDataComponent.h"

#include "GameInstances/MyGameInstance.h"

#include "Kismet/GameplayStatics.h"

UGameDataComponent::UGameDataComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGameDataComponent::BeginPlay()
{
	Super::BeginPlay();

	if (ReceiveGameData())
	{
		CreateAttendance();
	}
}

void UGameDataComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UGameDataComponent::ReceiveGameData()
{
	UMyGameInstance* GI = GetWorld()->GetGameInstance<UMyGameInstance>();

	if (IsValid(GI))
	{
		GameDataReference =  GI->SendGameDataByGameName(GameNameKey);
	}

	// ���������O�Ȃ�false
	return !GameDataReference.GameName.Compare(FName());
}

void UGameDataComponent::CreateAttendance()
{
	UMyGameInstance* GI = GetWorld()->GetGameInstance<UMyGameInstance>();

	if (IsValid(GI))
	{
		// 2�l���[�h�Ȃ�v���C���[����l�ǉ�����B
		if (GI->GetNumOfPlayerMode() == ENumOfPlayerMode::TWO_PLAYERMODE)
		{
			UGameplayStatics::CreatePlayer(GetWorld(), 1);
		}
	}

	// PlayerList��PlayerController��ێ�
	TArray<AActor*> ActorList;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerController::StaticClass(), ActorList);
	for (AActor* Act : ActorList)
	{
		PlayerList.Add(Cast<APlayerController>(Act));
	}

	// CPU�̐����J�E���g
	if (GameDataReference.Attendance.bShouldCreateCPU)
	{
		// CPU���܂߂��ő�Player�l�� - �����v���C���[�l��
		CPUNum = (int32)GameDataReference.Attendance.MaxAttendance - PlayerList.Num();
		CPUNum = FMath::Max(CPUNum, 0);
	}
}

