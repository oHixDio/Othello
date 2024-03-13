// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/ScreenCursorPawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AScreenCursorPawn::AScreenCursorPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AScreenCursorPawn::BeginPlay()
{
	Super::BeginPlay();

	
}
/*
void AScreenCursorPawn::ScreenCorsorMove(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// mouse��Screen���W�擾
		float MouseX, MouseY;
		PlayerController->GetMousePosition(MouseX,MouseY);

		// View�̑傫���擾
		int32 ViewX, ViewY;
		PlayerController->GetViewportSize(ViewX, ViewY);
		UE_LOG(LogTemp, Warning, TEXT("X:%d,Y:%d"), ViewX, ViewY);
		// ���͒l�𐳋K��
		MovementVector.Normalize();
		
		// ���Z
		int X = MovementVector.X * CorsorSpeed + MouseX;
		int Y = MovementVector.Y * CorsorSpeed + MouseY;

		// ����
		if (X < 0)
		{
			X = 0;
		}
		else if (X > ViewX)
		{
			X = ViewX;
		}

		if (Y < 0)
		{
			Y = 0;
		}
		else if (Y > ViewY)
		{
			Y = ViewY;
		}

		// Mouse�ʒu�X�V
		PlayerController->SetMouseLocation(X, Y);
	}
	ScreenCorsorWidget->Move(MovementVector);

	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}
*/
// Called every frame
void AScreenCursorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AScreenCursorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

