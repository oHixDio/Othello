// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FadeWidgetComponent.generated.h"

class UFadeWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OTHELLO_API UFadeWidgetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, Category = "Component | Asset")
	TSubclassOf<UFadeWidget> FadeWidgetClass;

	UFadeWidgetComponent();

	void FadeOut();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Component | Widget")
	UFadeWidget* FadeWidget;

	// Called when the game starts
	virtual void BeginPlay() override;



};
