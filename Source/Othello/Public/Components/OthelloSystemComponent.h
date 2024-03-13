// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Data/OthelloSquareType.h>
#include <Data/OthelloPieceColor.h>
#include "OthelloSystemComponent.generated.h"

class AOthelloSquare;
class AOthelloPiece;
class AOthelloGameModeBase;

USTRUCT()
struct FOthelloInfoData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	uint8 PassCount;

	UPROPERTY()
	uint8 TotalPlaceCount;

	UPROPERTY()
	uint8 BlackPlaceCount;

	UPROPERTY()
	uint8 WhitePlaceCount;

	UPROPERTY()
	uint32 BlackScore;

	UPROPERTY()
	uint32 WhiteScore;

	UPROPERTY()
	TArray<AOthelloSquare*> CurrentCanPlaceSquareList;
	UPROPERTY()
	TArray<AOthelloSquare*> CurrentSholudFlipSquareList;

	UPROPERTY(VisibleAnywhere, Category = "Othello | Data")
	EOthelloPieceColor CurrentPlaceColor;

	FOthelloInfoData() :
		PassCount(0),
		TotalPlaceCount(0),
		BlackPlaceCount(0),
		WhitePlaceCount(0),
		BlackScore(0),
		WhiteScore(0),
		CurrentCanPlaceSquareList(TArray<AOthelloSquare*>()),
		CurrentSholudFlipSquareList(TArray<AOthelloSquare*>()),
		CurrentPlaceColor(EOthelloPieceColor::BLACK)
	{
	};

	void InitAll()
	{
		PassCount = 0;
		TotalPlaceCount = 0;
		BlackPlaceCount = 0;
		WhitePlaceCount = 0;
		BlackScore = 0;
		WhiteScore = 0;
		CurrentCanPlaceSquareList.Empty();
		CurrentSholudFlipSquareList.Empty();
	};

	void InitPart()
	{
		PassCount = 0;
		CurrentCanPlaceSquareList.Empty();
		CurrentSholudFlipSquareList.Empty();
	};

};

USTRUCT()
struct FOthelloData
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(VisibleAnywhere, Category = "Othello | Data")
	int8 MAX_ROW;

	UPROPERTY(VisibleAnywhere, Category = "Othello | Data")
	int8 MAX_COL;

	UPROPERTY(VisibleAnywhere, Category = "Othello | Data")
	uint8 MAX_PASS;

	UPROPERTY(EditAnywhere, Category = "Othello | Data")
	TSubclassOf<AOthelloPiece> PlacementPieceClass;

	FOthelloData() :
		MAX_ROW(8),
		MAX_COL(8),
		MAX_PASS(2),
		PlacementPieceClass(nullptr)
	{
	};

	int32 SquareNum() const
	{
		return MAX_ROW * MAX_COL;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OTHELLO_API UOthelloSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOthelloSystemComponent();
	virtual void BeginPlay() override;
	
	//====================================================================================================================================================================================
	// Othello Info Data 
	//====================================================================================================================================================================================

public:
	const FOthelloInfoData& GetOthelloInfo() const { return OthelloInfoData; };

	void UpdateOthelloInfo();
protected:
	UPROPERTY()
	FOthelloInfoData OthelloInfoData;


	//====================================================================================================================================================================================
	// Othello System Main
	//====================================================================================================================================================================================
public:
	bool Placement(AOthelloSquare* TargetSquare);

	void AutoPlace();

	void InitSystem();

	void UpdateSystem();
protected:
	UPROPERTY(VisibleAnywhere, Category = "Othello | System | Actor")
	TArray<AOthelloSquare*> SquareList;

	UPROPERTY(EditAnywhere, Category = "Othello | System | Data")
	FOthelloData OthelloData;


	void Flip(AOthelloSquare* PlacingSquare);
	void FlipPieces(AOthelloSquare* Square, int32 FlipPieceAmount, int32 DirRow, int32 DirCol);
	int32 FlipPiecesCountByDir(AOthelloSquare* Square, int32 DirRow, int32 DirCol);

	AOthelloSquare* FindBestPlaceSquare();

	bool CanPlaceCheckAll();
	bool CanPlaceCheck(AOthelloSquare* Square);


	//====================================================================================================================================================================================
	// Othello System Sub
	//====================================================================================================================================================================================
public:
	FORCEINLINE EOthelloPieceColor GetCurrentColor() const { return GetOthelloInfo().CurrentPlaceColor; };
protected:
	FORCEINLINE FOthelloInfoData& OthelloInfo() { return OthelloInfoData; };

	FORCEINLINE int32 Index(const int32 ROW, const  int32 COL) const { return COL * OthelloData.MAX_ROW + ROW; };
	// オセロを行うにあたって、適切な枚数のSquareが取得できているかどうか。
	FORCEINLINE bool IsAppropriateBoard() const { return SquareList.Num() == OthelloData.SquareNum(); };

	FORCEINLINE bool IsInBoard(const int32 ROW, const  int32 COL) const { return (ROW >= 0 && ROW < OthelloData.MAX_ROW) && (COL >= 0 && COL < OthelloData.MAX_COL); };
		
	FORCEINLINE bool IsCornerSquare(const int32 ROW, const int32 COL) const { return (COL == 0 || COL == OthelloData.MAX_COL - 1) && (ROW == 0 || ROW == OthelloData.MAX_ROW - 1); };

	FORCEINLINE bool IsNoneColor(const EOthelloPieceColor Color) const { return Color == EOthelloPieceColor::NONE; };

	FORCEINLINE bool IsMatchColor(const EOthelloPieceColor leftColor, const EOthelloPieceColor rightColor)	const { return leftColor == rightColor; };

	FORCEINLINE EOthelloPieceColor GetAnotherColor(const EOthelloPieceColor Color)	const { return Color == EOthelloPieceColor::BLACK ? EOthelloPieceColor::WHITE : EOthelloPieceColor::BLACK; };
	
};
