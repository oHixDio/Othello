// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FadeWidgetComponent.h"
#include "UserInterfaces/Widgets/FadeWidget.h"
#include "Animation/WidgetAnimation.h"

// Sets default values for this component's properties
UFadeWidgetComponent::UFadeWidgetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFadeWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	
	if (FadeWidgetClass)
	{
		FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeWidgetClass);
		FadeWidget->AddToPlayerScreen(9999);
	}

	if (FadeWidget)
	{
		FadeWidget->FadeIn();
	}
}

void UFadeWidgetComponent::FadeOut()
{
	if (FadeWidget)
	{
		FadeWidget->FadeOut();
	}
}

