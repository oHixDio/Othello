// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStateBases/OthelloGameStateBase.h"

#include "Actors/OthelloSquare.h"
#include "Actors/OthelloPiece.h"
#include "UserInterfaces/Widgets/PopupTextWidget.h"


AOthelloGameStateBase::AOthelloGameStateBase()
{
	
}

void AOthelloGameStateBase::BeginPlay()
{
	Super::BeginPlay();
}

void AOthelloGameStateBase::ChangeState(EOthelloState NewState)
{
	EntryState(State);
	State = NewState;
	ExitState(State);
}

void AOthelloGameStateBase::EntryState(EOthelloState CurrentState)
{
	switch (CurrentState)
	{
	case EOthelloState::READY:
		break;
	case EOthelloState::PLAY:
		break;
	case EOthelloState::RESULT:
		break;
	default:
		break;
	}
}

void AOthelloGameStateBase::ExitState(EOthelloState CurrentState)
{
	switch (CurrentState)
	{
	case EOthelloState::READY:
		break;
	case EOthelloState::PLAY:
		break;
	case EOthelloState::RESULT:
		break;
	default:
		break;
	}
}
