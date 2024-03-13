// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OthelloSquare.h"
#include "Actors/OthelloPiece.h"

#include "Components/OthelloSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UOthelloSystemComponent::UOthelloSystemComponent()
{

}

void UOthelloSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// 念の為空にする。
	SquareList.Empty();
	SquareList.Reserve(OthelloData.SquareNum());

	// Level内のSquareタグがついているAOthelloSquareクラスのアクタを全て取得する
	TArray<AActor*> levelPlacementSquareList;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AOthelloSquare::StaticClass(), TEXT("Square"), levelPlacementSquareList);
	for (AActor* Actor : levelPlacementSquareList)
	{
		if (AOthelloSquare* Square = Cast<AOthelloSquare>(Actor))
		{
			SquareList.Emplace(Square);
		}
	}
	// Sort ※必須
	SquareList.Sort([](const AOthelloSquare& LHS, const AOthelloSquare& RHS) { return LHS < RHS; });

	if (IsAppropriateBoard())
	{
		// 中央4枚のPieceを生成
		SquareList[Index(3, 3)]->PlacePiece(OthelloData.PlacementPieceClass, EOthelloPieceColor::BLACK);
		SquareList[Index(4, 4)]->PlacePiece(OthelloData.PlacementPieceClass, EOthelloPieceColor::BLACK);
		SquareList[Index(4, 3)]->PlacePiece(OthelloData.PlacementPieceClass, EOthelloPieceColor::WHITE);
		SquareList[Index(3, 4)]->PlacePiece(OthelloData.PlacementPieceClass, EOthelloPieceColor::WHITE);
	}

}

void UOthelloSystemComponent::UpdateOthelloInfo()
{

}

bool UOthelloSystemComponent::Placement(AOthelloSquare* TargetSquare)
{
	if (!GetOthelloInfo().CurrentCanPlaceSquareList.Contains(TargetSquare))
	{
		return false; 
	}

	// 配置するSquare取得
	int32 PlacingSquareIndex = GetOthelloInfo().CurrentCanPlaceSquareList.IndexOfByKey(TargetSquare);
	AOthelloSquare* PlacingSquare = GetOthelloInfo().CurrentCanPlaceSquareList[PlacingSquareIndex];

	// 配置
	PlacingSquare->PlacePiece(OthelloData.PlacementPieceClass, GetOthelloInfo().CurrentPlaceColor);

	// 配置したPieceを元に反転させる
	Flip(PlacingSquare);

	return true;
}

void UOthelloSystemComponent::AutoPlace()
{
	AOthelloSquare* PlacingSquare = FindBestPlaceSquare();

	if (PlacingSquare)
	{
		Placement(PlacingSquare);
	}
}

void UOthelloSystemComponent::InitSystem()
{
	OthelloInfo().InitPart();

}

void UOthelloSystemComponent::UpdateSystem()
{
	bool bCanPlace = CanPlaceCheckAll();

	if (bCanPlace)
	{

	}
	else
	{
		OthelloInfo().PassCount++;
	}
}

AOthelloSquare* UOthelloSystemComponent::FindBestPlaceSquare()
{
	// 角なら優先して取得する
	for (AOthelloSquare* Square : OthelloInfo().CurrentCanPlaceSquareList)
	{
		const int32 ROW = Square->GetRow();
		const int32 COL = Square->GetCol();
		if (IsCornerSquare(ROW, COL))
		{
			return Square;
		}
	}

	// ランダムな場所を返す
	const int32 length = OthelloInfo().CurrentCanPlaceSquareList.Num();
	int32 index = FMath::RandHelper(length);

	return OthelloInfo().CurrentCanPlaceSquareList[index];
}

bool UOthelloSystemComponent::CanPlaceCheckAll()
{
	for (AOthelloSquare* Square : SquareList)
	{
		// Pieceを置けるか
		if (CanPlaceCheck(Square))
		{
			OthelloInfo().CurrentCanPlaceSquareList.Add(Square);
		}
	}

	return GetOthelloInfo().CurrentCanPlaceSquareList.Num() != 0;
}
bool UOthelloSystemComponent::CanPlaceCheck(AOthelloSquare* Square)
{
	// NONE指定ならば終了する。
	if (IsNoneColor(GetCurrentColor())) { return false; }

	// SquareにPieceがすでにおいてあるならば、終了する。
	if (!IsNoneColor(Square->GetCurrentColor())) { return false; }

	const int32 ROW = Square->GetRow();
	const int32 COL = Square->GetCol();

	// 周囲8マス走査
	for (int32 c = -1; c <= 1; c++)
	{
		for (int32 r = -1; r <= 1; r++)
		{
			// Centerは調べなくてよい
			if (c == 0 && r == 0) { continue; }

			// 周囲8マスの行と列
			int32 AroundRow = r + ROW;
			int32 AroundCol = c + COL;
			
			// Board外なら調べない
			// Pieceが置かれていないなら調べない。
			// 同じ色なら調べない。
			if (!IsInBoard(AroundRow, AroundCol)) { continue; }
			if (IsNoneColor(SquareList[Index(AroundRow, AroundCol)]->GetCurrentColor())) { continue; }
			if (IsMatchColor(SquareList[Index(AroundRow, AroundCol)]->GetCurrentColor(), this->GetCurrentColor())) { continue; }

			/* ===↓周囲マスに違う色のPieceが置かれている場合到達↓=== */

			// 周囲マスの次のマス
			int32 NextRow = AroundRow + r;
			int32 NextCol = AroundCol + c;

			// Board内かつ、Pieceが配置されている
			while (IsInBoard(NextRow, NextCol) && !IsNoneColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor()))
			{
				/* ===同一色のPieceをみつけたのでPieceは置ける=== */
				if (IsMatchColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor(), this->GetCurrentColor()))
				{
					return true;
				}

				// 次のマスへ
				NextRow += r;
				NextCol += c;
			}
		}
	}
	/* ===Pieceは置けない=== */
	return false;
}

void UOthelloSystemComponent::Flip(AOthelloSquare* PlacingSquare)
{
	// 周囲8マス走査
	for (int32 c = -1; c <= 1; c++)
	{
		for (int32 r = -1; r <= 1; r++)
		{
			// CenterSquareは調べなくてよい
			if (c == 0 && r == 0) { continue; }
			// 1方向の反転数を調べる
			int32 FlipAmount = FlipPiecesCountByDir(PlacingSquare, r, c);
			// 反転数分判定していく
			FlipPieces(PlacingSquare, FlipAmount, r, c);

		}
	}
}
void UOthelloSystemComponent::FlipPieces(AOthelloSquare* Square, int32 FlipPieceAmount, int32 DirRow, int32 DirCol)
{
	// 周囲8マスのいずれかとなる。
	int32 NextRow = Square->GetRow() + DirRow;
	int32 NextCol = Square->GetCol() + DirCol;

	// フリップ回数
	while (IsInBoard(NextRow,NextCol) && FlipPieceAmount-- > 0)
	{
		// 反転させる
		SquareList[Index(NextRow, NextCol)]->ReversePlacedPiece();

		// 次のSquareへ
		NextRow += DirRow;
		NextCol += DirCol;
	}
}
int32 UOthelloSystemComponent::FlipPiecesCountByDir(AOthelloSquare* Square, int32 DirRow, int32 DirCol)
{
	// 渡されたスクエアの渡された方角のROW,COLを取得
	int32 RetNum = 0;
	int32 NextRow = Square->GetRow() + DirRow;
	int32 NextCol = Square->GetCol() + DirCol;

	EOthelloSquareType CenterSquareType = Square->GetCurrentType();

	// Board内である。
	while (IsInBoard(NextRow, NextCol))
	{
		// Pieceが置かれていなかった
		if (IsNoneColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor()))
		{
			return 0;
		}
		// Pieceが同じ色だった。
		if (IsMatchColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor(), GetCurrentColor()))
		{
			return RetNum;
		}

		// 次のSquareへ
		NextRow += DirRow;
		NextCol += DirCol;
		// 違う色が何個あったかカウントする。
		RetNum++;
	}
	
	// 同じ色のPieceが見つからなかった。
	return 0;
}
