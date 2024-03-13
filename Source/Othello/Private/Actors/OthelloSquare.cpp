// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OthelloSquare.h"
#include "Actors/OthelloPiece.h"

#include "UserInterfaces/CountNumberWidget.h"

#include "Components/WidgetComponent.h"

// Sets default values
AOthelloSquare::AOthelloSquare()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("RootMesh");
	SetRootComponent(Mesh);

	ReverseCountWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("Widget Component");
	ReverseCountWidgetComponent->SetupAttachment(RootComponent);
	ReverseCountWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	ReverseCountWidgetComponent->SetDrawSize(FVector2D(50));
	ReverseCountWidgetComponent->SetDrawAtDesiredSize(true);
	ReverseCountWidgetComponent->SetVisibility(false);
}

void AOthelloSquare::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AOthelloSquare::Init()
{
	SquareData.Init();

	CountNumberWidget = Cast<UCountNumberWidget>(ReverseCountWidgetComponent->GetWidget());
}

void AOthelloSquare::Reset()
{
	if (SquareData.PlacedPiece != nullptr)
	{
		SquareData.PlacedPiece->Destroy();
	}
	SquareData.Reset();
	CountNumberWidget->SetNumber(SquareData.ReverseCnt);
	ReverseCountWidgetComponent->SetVisibility(false);
}

void AOthelloSquare::SetCurrentType(const EOthelloSquareType NewType)
{
	SquareData.CurrentType = NewType;
}

void AOthelloSquare::SetCurrentType(const EOthelloPieceColor NewColor)
{
	SquareData.CurrentColor = NewColor;
}

void AOthelloSquare::SetCanPlace(const bool bCanPlace)
{
	SquareData.bCanPlace = bCanPlace;
}

bool AOthelloSquare::PlacePiece(TSubclassOf<AOthelloPiece> PieceClass, EOthelloSquareType Type)
{
	// Pieceの色を決める。
	EOthelloPieceColor Color = Type == EOthelloSquareType::BLACK ? EOthelloPieceColor::BLACK : EOthelloPieceColor::WHITE;

	// Spawnさせ、SpawnアクタのBeginPlay実行前に処理を走らせる方法。以下3行
	AOthelloPiece* const Piece = GetWorld()->SpawnActorDeferred<AOthelloPiece>(PieceClass, GetActorTransform());
	Piece->Init();
	Piece->Reverse(Color);    // BeginPlay前に実行したい処理
	Piece->FinishSpawning(GetActorTransform());    // スポーン処理
	
	// Pieceの生成に失敗している場合、終了する。
	if (!Piece) { return false; }

	SetCurrentType(Type);
	SquareData.PlacedPiece = Piece;
	SquareData.PlacedPiece->SetActorLocation(GetActorLocation() + SquareData.PlaceOffset);
	ReverseCountWidgetComponent->SetVisibility(true);

	return true;
}

bool AOthelloSquare::PlacePiece(TSubclassOf<AOthelloPiece> PieceClass, EOthelloPieceColor Color)
{

	// Spawnさせ、SpawnアクタのBeginPlay実行前に処理を走らせる方法。以下3行
	AOthelloPiece* const Piece = GetWorld()->SpawnActorDeferred<AOthelloPiece>(PieceClass, GetActorTransform());
	Piece->Init();
	Piece->Reverse(Color);    // BeginPlay前に実行したい処理
	Piece->FinishSpawning(GetActorTransform());    // スポーン処理

	// Pieceの生成に失敗している場合、終了する。
	if (!Piece) { return false; }

	SetCurrentType(Color);
	SquareData.PlacedPiece = Piece;
	SquareData.PlacedPiece->SetActorLocation(GetActorLocation() + SquareData.PlaceOffset);
	ReverseCountWidgetComponent->SetVisibility(true);

	return true;
}

void AOthelloSquare::ReversePlacedPiece()
{
	if (GetPlacedPiece())
	{
		// 裏の色を取得
		EOthelloSquareType NewType = SquareData.CurrentType == EOthelloSquareType::BLACK ? EOthelloSquareType::WHITE : EOthelloSquareType::BLACK;
		EOthelloPieceColor NewColor = NewType == EOthelloSquareType::BLACK ? EOthelloPieceColor::BLACK : EOthelloPieceColor::WHITE;
		SetCurrentType(NewType);
		GetPlacedPiece()->Reverse(NewColor);

		SquareData.ReverseCnt++;
		CountNumberWidget->SetNumber(SquareData.ReverseCnt);
	}
}

void AOthelloSquare::ReversePlacedPiece(EOthelloPieceColor Color)
{
	if (GetPlacedPiece())
	{
		EOthelloPieceColor NewColor = Color == EOthelloPieceColor::BLACK ? EOthelloPieceColor::WHITE : EOthelloPieceColor::BLACK;
		SetCurrentType(NewColor);
		GetPlacedPiece()->Reverse(NewColor);

		SquareData.ReverseCnt++;
		CountNumberWidget->SetNumber(SquareData.ReverseCnt);
	}
}

void AOthelloSquare::TwoTimesReverseConut()
{
	SquareData.ReverseCnt *= 2;
	CountNumberWidget->SetNumber(SquareData.ReverseCnt);
}

void AOthelloSquare::DebugColorChange(ESquareDebugColor Color)
{
	switch (Color)
	{
	case ESquareDebugColor::ORIGINAL:
		Mesh->SetMaterial(0, Debug_DefaultColor);
		break;
	case ESquareDebugColor::PLACEMENT:
		Mesh->SetMaterial(0, Debug_CanPlaceColor);
		break;
	case ESquareDebugColor::AROUND:
		Mesh->SetMaterial(0, Debug_AroundColor);
		break;
	default:
		break;
	}
}