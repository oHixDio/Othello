// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "CursorWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class OTHELLO_API UCursorWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

protected:
	UCursorWidgetComponent();
	virtual void BeginPlay() override;

	
};
