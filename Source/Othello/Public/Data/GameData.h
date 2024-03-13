// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.generated.h"


UENUM()
enum class ENumOfPlayerMode : uint8
{
	ONE_PLAYERMODE = 1 UMETA(DisplayName = "ONE_PLAYERMODE"),
	TWO_PLAYERMODE = 2 UMETA(DisplayName = "TWO_PLAYERMODE"),
};

USTRUCT()
struct FAttendance
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Attendance")
	ENumOfPlayerMode MaxAttendance;

	UPROPERTY(EditAnywhere, Category = "Attendance")
	bool bShouldCreateCPU;

	FAttendance() :
		MaxAttendance(ENumOfPlayerMode::ONE_PLAYERMODE),
		bShouldCreateCPU(true)
	{
	};
};

USTRUCT()
struct FGameData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Attendance")
	FName GameName;

	UPROPERTY(EditAnywhere, Category = "Attendance")
	FAttendance Attendance;

	FGameData() :
		GameName(FName()),
		Attendance(FAttendance())
	{
	};
};