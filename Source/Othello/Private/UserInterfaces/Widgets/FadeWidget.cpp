// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/Widgets/FadeWidget.h"
#include "Kismet/GameplayStatics.h"


void UFadeWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	bShowViewPort = false;

	EndDelegate.BindDynamic(this, &UFadeWidget::AnimationFinished);

	if (EndDelegate.IsBound())
	{
		BindToAnimationFinished(FadeAnimation, EndDelegate);
	}
	UE_LOG(LogTemp, Warning, TEXT("Initialized"));
}

void UFadeWidget::FadeIn()
{
	if (FadeAnimation)
	{
		PlayAnimationForward(FadeAnimation);
		bShowViewPort = true;
	}
}

void UFadeWidget::FadeOut(TSoftObjectPtr<UWorld> Level)
{
	if (FadeAnimation)
	{
		SetVisibility(ESlateVisibility::Visible);
		PlayAnimationReverse(FadeAnimation);
		bShowViewPort = false;
		
		LoadLevel = Level;
	}
}

void UFadeWidget::AnimationFinished()
{
	if (bShowViewPort)
	{
		SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		if (UKismetSystemLibrary::IsValidSoftObjectReference(LoadLevel))
		{
			UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), LoadLevel);
			LoadLevel = nullptr;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Level Name is None"));
		}
	}
	
}