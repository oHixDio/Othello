// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Data/OthelloPieceColor.h>
#include "OthelloPiece.generated.h"

USTRUCT()
struct FOthelloPieceAnimationData
{
	GENERATED_USTRUCT_BODY()

	FOthelloPieceAnimationData() :
		Duration(1.0f),
		FloatTurnTimes(1.0f),
		FloatAmount(1.0f)
	{
	};
	UPROPERTY(EditAnywhere)
	float Duration;

	UPROPERTY(EditAnywhere)
	float FloatTurnTimes;

	UPROPERTY(EditAnywhere)
	float FloatAmount;

	UPROPERTY(VisibleAnywhere)
	FVector StartLocation;

	UPROPERTY(VisibleAnywhere)
	FRotator StartRotation;
};

UCLASS()
class OTHELLO_API AOthelloPiece : public AActor
{
	GENERATED_BODY()
	
public:
	//====================================================================================================================================================================================
	// Field
	//====================================================================================================================================================================================
	
	//====================================================================================================================================================================================
	// Method
	//====================================================================================================================================================================================
	AOthelloPiece();
	virtual void Tick(float DeltaTime) override;

	// êFÇïœÇ¶ÇÈ
	void Reverse(EOthelloPieceColor NewColor = EOthelloPieceColor::BLACK);

	FORCEINLINE EOthelloPieceColor GetCurrentColor() { return CurrentColor; };

	void SetColor(EOthelloPieceColor NewColor);

	void Init();


protected:
	//====================================================================================================================================================================================
	// Field
	//====================================================================================================================================================================================
	UPROPERTY(EditAnywhere, Category = "Othello | Piece | Component")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "Othello | Piece | Data")
	EOthelloPieceColor CurrentColor;

	UPROPERTY(EditAnywhere, Category = "Othello | Piece | Animation")
	FOthelloPieceAnimationData AnimData;

	//====================================================================================================================================================================================
	// Method
	//====================================================================================================================================================================================
	virtual void BeginPlay() override;

};
