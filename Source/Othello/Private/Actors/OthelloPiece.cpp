// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OthelloPiece.h"

// Sets default values
AOthelloPiece::AOthelloPiece()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Root Mesh Component");
	SetRootComponent(Mesh);
}

void AOthelloPiece::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOthelloPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOthelloPiece::Reverse(EOthelloPieceColor NewColor)
{
	if (CurrentColor != NewColor)
	{
		AddActorWorldRotation(FQuat(GetActorForwardVector(),PI));
	}
	SetColor(NewColor);
}

void AOthelloPiece::SetColor(EOthelloPieceColor NewColor)
{
	CurrentColor = NewColor;
}

void AOthelloPiece::Init()
{
	CurrentColor = EOthelloPieceColor::BLACK;
}
