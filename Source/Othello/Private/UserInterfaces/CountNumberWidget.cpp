// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/CountNumberWidget.h"

#include "Components/TextBlock.h"


void UCountNumberWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCountNumberWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	Number = 1;
	MaxNumber = 99;
	Number = FMath::Min(Number, MaxNumber);
	UpdateWidget();
}

void UCountNumberWidget::SetNumber(const int64 NewNumber)
{
	Number = NewNumber;
	Number = FMath::Min(Number, MaxNumber);
	UpdateWidget();
}

void UCountNumberWidget::IncrementNumber()
{
	Number++;
	Number = FMath::Min(Number, MaxNumber);
	UpdateWidget();
}

void UCountNumberWidget::DecrementNumber()
{
	Number--;
	Number = FMath::Min(Number, MaxNumber);
	UpdateWidget();
}

void UCountNumberWidget::CountUp(int64 TargetNumber)
{

}

void UCountNumberWidget::CountDown(int64 TargetNumber)
{
}

void UCountNumberWidget::UpdateWidget()
{
	NumberText->SetText(FText::AsNumber(Number));
}

