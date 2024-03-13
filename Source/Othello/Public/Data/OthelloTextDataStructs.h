// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "OthelloTextDataStructs.generated.h"


USTRUCT()
struct FTurnTextData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FText TurnText;

	UPROPERTY(EditAnywhere, Category = "Widget | Data")
	FText ColorText;
};