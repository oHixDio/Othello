// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/OthelloPlayerController.h"

#include "GameModeBases/OthelloGameModeBase.h"
#include "HUDs/OthelloHUD.h"
#include "Components/OthelloSystemComponent.h"
#include "Components/OthelloPlayerComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

AOthelloPlayerController::AOthelloPlayerController()
	:Super()
{
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
}

void AOthelloPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = GetWorld()->GetAuthGameMode<AOthelloGameModeBase>();
	HUD = GetHUD<AOthelloHUD>();

	if (GameMode)
	{
		GameMode->JoinPlayer(this);
	}

	// Levelからカメラを取得して定点カメラとして利用する
	FixedCamera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	if (FixedCamera)
	{
		SetViewTarget(FixedCamera);
	}

	// Othello用のIMCを追加
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(OthelloMappingContext, 0);
	}
}

void AOthelloPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOthelloPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Othelloのメインの動きを実装
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Started, this, &AOthelloPlayerController::OnBeginClick);
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Completed, this, &AOthelloPlayerController::OnEndClick);

		EnhancedInputComponent->BindAction(DebugAction1, ETriggerEvent::Started, this, &AOthelloPlayerController::OnDebugAction1);
		EnhancedInputComponent->BindAction(DebugAction2, ETriggerEvent::Started, this, &AOthelloPlayerController::OnDebugAction2);
	}
}

FText AOthelloPlayerController::GetGameTextOfGameMode() const
{
	return FText::FromName(GameMode->GetGameName());
}

void AOthelloPlayerController::Enabled()
{
	SetShowMouseCursor(true);
	EnableInput(this);
}

void AOthelloPlayerController::SemiEnabled()
{
	// カーソル移動できる
	// マウスカーソルの色薄い
	// ゲーム進行に関わる操作できない
	// ポーズできる
}

void AOthelloPlayerController::Disabled()
{
	SetShowMouseCursor(false);
	DisableInput(this);
}

void AOthelloPlayerController::OnBeginClick(const FInputActionValue& Value)
{
	// マウス下部のアクタを保持
	FHitResult HitResult;
	bool bHasHit = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
	if (bHasHit)
	{
		ClickedActor = HitResult.GetActor();
	}
}
void AOthelloPlayerController::OnClick(const FInputActionValue& Value)
{
	if (ClickedActor)
	{
		if (GameMode)
		{
			GameMode->Placement(ClickedActor);
		}
	}
}
void AOthelloPlayerController::OnEndClick(const FInputActionValue& Value)
{
	FHitResult HitResult;
	bool bHasHit = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
	if (bHasHit)
	{
		// マウス下部のアクタとクリックStart時に保持したアクタが同一ならばClick本処理
		if (HitResult.GetActor() == ClickedActor)
		{
			OnClick(Value);
			ClickedActor = nullptr;
		}
	}
}

void AOthelloPlayerController::OnDebugAction1(const FInputActionValue& Value)
{
	if (GameMode)
	{
		GameMode->Start();
	}
}

void AOthelloPlayerController::OnDebugAction2(const FInputActionValue& Value)
{
	
}
