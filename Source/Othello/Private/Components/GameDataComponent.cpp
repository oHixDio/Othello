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

	// 文字数が０ならfalse
	return !GameDataReference.GameName.Compare(FName());
}

void UGameDataComponent::CreateAttendance()
{
	UMyGameInstance* GI = GetWorld()->GetGameInstance<UMyGameInstance>();

	if (IsValid(GI))
	{
		// 2人モードならプレイヤーを一人追加する。
		if (GI->GetNumOfPlayerMode() == ENumOfPlayerMode::TWO_PLAYERMODE)
		{
			UGameplayStatics::CreatePlayer(GetWorld(), 1);
		}
	}

	// PlayerListにPlayerControllerを保持
	TArray<AActor*> ActorList;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerController::StaticClass(), ActorList);
	for (AActor* Act : ActorList)
	{
		PlayerList.Add(Cast<APlayerController>(Act));
	}

	// CPUの数をカウント
	if (GameDataReference.Attendance.bShouldCreateCPU)
	{
		// CPUを含めた最大Player人数 - 生成プレイヤー人数
		CPUNum = (int32)GameDataReference.Attendance.MaxAttendance - PlayerList.Num();
		CPUNum = FMath::Max(CPUNum, 0);
	}
}

