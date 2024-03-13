// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Data/OthelloSquareType.h>
#include <Data/OthelloPieceColor.h>
#include "OthelloSquare.generated.h"

class AOthelloPiece;

UENUM()
enum class ESquareDebugColor : uint8
{
	ORIGINAL,
	PLACEMENT,
	AROUND,
};

USTRUCT()
struct FOthelloSquareData
{
	GENERATED_USTRUCT_BODY()

	FOthelloSquareData() :
		CurrentType(EOthelloSquareType::NONE),
		Weight(0),
		ReverseCnt(1),
		Number(0),
		Row(Number % 8),
		Col(Number / 8),
		bCanPlace(false),
		PlaceOffset(FVector()),
		PlacedPiece(nullptr)
	{
	};

	// 所持するPieceの色
	UPROPERTY(VisibleAnywhere, Category = "Square Data")
	EOthelloSquareType CurrentType;

	// 所持するPieceの色
	UPROPERTY(VisibleAnywhere, Category = "Square Data")
	EOthelloPieceColor CurrentColor;

	// 重さの評価用
	UPROPERTY(EditInstanceOnly, Category = "Square Data")
	int32 Weight;

	// 反転数の評価用
	UPROPERTY(EditInstanceOnly, Category = "Square Data")
	uint32 ReverseCnt;

	UPROPERTY(EditInstanceOnly, Category = "Square Data")
	int32 Number;

	UPROPERTY(VisibleAnywhere, Category = "Square Data")
	int32 Row;

	UPROPERTY(VisibleAnywhere, Category = "Square Data")
	int32 Col;

	UPROPERTY(VisibleAnywhere, Category = "Square Data")
	bool bCanPlace;

	UPROPERTY(EditDefaultsOnly, Category = "Square Data")
	FVector PlaceOffset;

	UPROPERTY(VisibleAnywhere, Category = "Square Data")
	AOthelloPiece* PlacedPiece;
	
	void Init()
	{
		Row = Number % 8;
		Col = Number / 8;
		ReverseCnt = 1;
	}

	void Reset()
	{
		CurrentType = EOthelloSquareType::NONE;
		ReverseCnt = 1;
		bCanPlace = false;
		PlacedPiece = nullptr;
	}
};

UCLASS()
class OTHELLO_API AOthelloSquare : public AActor
{
	GENERATED_BODY()

public:
	//====================================================================================================================================================================================
	// Field
	//====================================================================================================================================================================================
	UPROPERTY(EditAnywhere)
	UMaterialInstance* Debug_DefaultColor;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* Debug_CanPlaceColor;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* Debug_AroundColor;
	//====================================================================================================================================================================================
	// Method
	//====================================================================================================================================================================================
	AOthelloSquare();

	// 3評価Data
	FORCEINLINE EOthelloSquareType GetCurrentType() const { return SquareData.CurrentType; };
	FORCEINLINE EOthelloPieceColor GetCurrentColor() const { return SquareData.CurrentColor; };
	FORCEINLINE int32 GetWeight() const { return SquareData.Weight; };
	FORCEINLINE int32 GetReverseCount() const { return SquareData.ReverseCnt; };

	// 検索用IndexData
	FORCEINLINE int32 GetNumber() const { return SquareData.Number; };
	FORCEINLINE int32 GetRow() const { return SquareData.Row; };
	FORCEINLINE int32 GetCol() const { return SquareData.Col; };

	// 配置可能かどうか
	FORCEINLINE bool GetCanPlace() const { return SquareData.bCanPlace; }
	FORCEINLINE bool HasPiece() const { return IsValid(SquareData.PlacedPiece); };

	// 所持するPiece
	FORCEINLINE AOthelloPiece* GetPlacedPiece() const { return SquareData.PlacedPiece; };

	void SetCurrentType(const EOthelloSquareType NewType);
	void SetCurrentType(const EOthelloPieceColor NewColor);
	void SetCanPlace(const bool bCanPlace);


	// 駒を指定色で生成する。
	bool PlacePiece(TSubclassOf<AOthelloPiece> PieceClass, EOthelloSquareType Type);
	bool PlacePiece(TSubclassOf<AOthelloPiece> PieceClass, EOthelloPieceColor Color);
	void ReversePlacedPiece();
	void ReversePlacedPiece(EOthelloPieceColor Color);
	void TwoTimesReverseConut();

	void Init();
	void Reset();

	
	// Debug用
	void DebugColorChange(ESquareDebugColor Color);

	// 自クラス配列を作成したときのソート方法を作成
	bool operator<(const AOthelloSquare& Other) const
	{
		return this->GetNumber() < Other.GetNumber();
	}
protected:
	//====================================================================================================================================================================================
	// Field
	//====================================================================================================================================================================================
	UPROPERTY(VisibleAnywhere, Category = "Othello | Square | Component")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Othello | Square | Component")
	class UCursorWidgetComponent* CursorWidgetComponent;

	UPROPERTY(EditAnywhere, Category = "Othello | Square | Component")
	class UWidgetComponent* PlaceGuideWidgetComponent;

	UPROPERTY(EditAnywhere, Category = "Othello | Square | Component")
	class UWidgetComponent* ReverseCountWidgetComponent;

	UPROPERTY(EditAnywhere, Category = "Othello | Square | Widget")
	class UCountNumberWidget* CountNumberWidget;

	UPROPERTY(EditAnywhere, Category = "Othello | Square | Data")
	FOthelloSquareData SquareData;
	//====================================================================================================================================================================================
	// Method
	//====================================================================================================================================================================================
	virtual void BeginPlay() override;

	
};
