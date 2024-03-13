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

	// �O�̈׋�ɂ���B
	SquareList.Empty();
	SquareList.Reserve(OthelloData.SquareNum());

	// Level����Square�^�O�����Ă���AOthelloSquare�N���X�̃A�N�^��S�Ď擾����
	TArray<AActor*> levelPlacementSquareList;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AOthelloSquare::StaticClass(), TEXT("Square"), levelPlacementSquareList);
	for (AActor* Actor : levelPlacementSquareList)
	{
		if (AOthelloSquare* Square = Cast<AOthelloSquare>(Actor))
		{
			SquareList.Emplace(Square);
		}
	}
	// Sort ���K�{
	SquareList.Sort([](const AOthelloSquare& LHS, const AOthelloSquare& RHS) { return LHS < RHS; });

	if (IsAppropriateBoard())
	{
		// ����4����Piece�𐶐�
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

	// �z�u����Square�擾
	int32 PlacingSquareIndex = GetOthelloInfo().CurrentCanPlaceSquareList.IndexOfByKey(TargetSquare);
	AOthelloSquare* PlacingSquare = GetOthelloInfo().CurrentCanPlaceSquareList[PlacingSquareIndex];

	// �z�u
	PlacingSquare->PlacePiece(OthelloData.PlacementPieceClass, GetOthelloInfo().CurrentPlaceColor);

	// �z�u����Piece�����ɔ��]������
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
	// �p�Ȃ�D�悵�Ď擾����
	for (AOthelloSquare* Square : OthelloInfo().CurrentCanPlaceSquareList)
	{
		const int32 ROW = Square->GetRow();
		const int32 COL = Square->GetCol();
		if (IsCornerSquare(ROW, COL))
		{
			return Square;
		}
	}

	// �����_���ȏꏊ��Ԃ�
	const int32 length = OthelloInfo().CurrentCanPlaceSquareList.Num();
	int32 index = FMath::RandHelper(length);

	return OthelloInfo().CurrentCanPlaceSquareList[index];
}

bool UOthelloSystemComponent::CanPlaceCheckAll()
{
	for (AOthelloSquare* Square : SquareList)
	{
		// Piece��u���邩
		if (CanPlaceCheck(Square))
		{
			OthelloInfo().CurrentCanPlaceSquareList.Add(Square);
		}
	}

	return GetOthelloInfo().CurrentCanPlaceSquareList.Num() != 0;
}
bool UOthelloSystemComponent::CanPlaceCheck(AOthelloSquare* Square)
{
	// NONE�w��Ȃ�ΏI������B
	if (IsNoneColor(GetCurrentColor())) { return false; }

	// Square��Piece�����łɂ����Ă���Ȃ�΁A�I������B
	if (!IsNoneColor(Square->GetCurrentColor())) { return false; }

	const int32 ROW = Square->GetRow();
	const int32 COL = Square->GetCol();

	// ����8�}�X����
	for (int32 c = -1; c <= 1; c++)
	{
		for (int32 r = -1; r <= 1; r++)
		{
			// Center�͒��ׂȂ��Ă悢
			if (c == 0 && r == 0) { continue; }

			// ����8�}�X�̍s�Ɨ�
			int32 AroundRow = r + ROW;
			int32 AroundCol = c + COL;
			
			// Board�O�Ȃ璲�ׂȂ�
			// Piece���u����Ă��Ȃ��Ȃ璲�ׂȂ��B
			// �����F�Ȃ璲�ׂȂ��B
			if (!IsInBoard(AroundRow, AroundCol)) { continue; }
			if (IsNoneColor(SquareList[Index(AroundRow, AroundCol)]->GetCurrentColor())) { continue; }
			if (IsMatchColor(SquareList[Index(AroundRow, AroundCol)]->GetCurrentColor(), this->GetCurrentColor())) { continue; }

			/* ===�����̓}�X�ɈႤ�F��Piece���u����Ă���ꍇ���B��=== */

			// ���̓}�X�̎��̃}�X
			int32 NextRow = AroundRow + r;
			int32 NextCol = AroundCol + c;

			// Board�����APiece���z�u����Ă���
			while (IsInBoard(NextRow, NextCol) && !IsNoneColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor()))
			{
				/* ===����F��Piece���݂����̂�Piece�͒u����=== */
				if (IsMatchColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor(), this->GetCurrentColor()))
				{
					return true;
				}

				// ���̃}�X��
				NextRow += r;
				NextCol += c;
			}
		}
	}
	/* ===Piece�͒u���Ȃ�=== */
	return false;
}

void UOthelloSystemComponent::Flip(AOthelloSquare* PlacingSquare)
{
	// ����8�}�X����
	for (int32 c = -1; c <= 1; c++)
	{
		for (int32 r = -1; r <= 1; r++)
		{
			// CenterSquare�͒��ׂȂ��Ă悢
			if (c == 0 && r == 0) { continue; }
			// 1�����̔��]���𒲂ׂ�
			int32 FlipAmount = FlipPiecesCountByDir(PlacingSquare, r, c);
			// ���]�������肵�Ă���
			FlipPieces(PlacingSquare, FlipAmount, r, c);

		}
	}
}
void UOthelloSystemComponent::FlipPieces(AOthelloSquare* Square, int32 FlipPieceAmount, int32 DirRow, int32 DirCol)
{
	// ����8�}�X�̂����ꂩ�ƂȂ�B
	int32 NextRow = Square->GetRow() + DirRow;
	int32 NextCol = Square->GetCol() + DirCol;

	// �t���b�v��
	while (IsInBoard(NextRow,NextCol) && FlipPieceAmount-- > 0)
	{
		// ���]������
		SquareList[Index(NextRow, NextCol)]->ReversePlacedPiece();

		// ����Square��
		NextRow += DirRow;
		NextCol += DirCol;
	}
}
int32 UOthelloSystemComponent::FlipPiecesCountByDir(AOthelloSquare* Square, int32 DirRow, int32 DirCol)
{
	// �n���ꂽ�X�N�G�A�̓n���ꂽ���p��ROW,COL���擾
	int32 RetNum = 0;
	int32 NextRow = Square->GetRow() + DirRow;
	int32 NextCol = Square->GetCol() + DirCol;

	EOthelloSquareType CenterSquareType = Square->GetCurrentType();

	// Board���ł���B
	while (IsInBoard(NextRow, NextCol))
	{
		// Piece���u����Ă��Ȃ�����
		if (IsNoneColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor()))
		{
			return 0;
		}
		// Piece�������F�������B
		if (IsMatchColor(SquareList[Index(NextRow, NextCol)]->GetCurrentColor(), GetCurrentColor()))
		{
			return RetNum;
		}

		// ����Square��
		NextRow += DirRow;
		NextCol += DirCol;
		// �Ⴄ�F�������������J�E���g����B
		RetNum++;
	}
	
	// �����F��Piece��������Ȃ������B
	return 0;
}
