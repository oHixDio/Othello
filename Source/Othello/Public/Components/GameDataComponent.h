// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include <Data/GameData.h>

#include "GameDataComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OTHELLO_API UGameDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGameDataComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	////////////////////////////////
	// GameData‚ğGameInstance‚©‚çó‚¯æ‚é
protected:
	UPROPERTY(EditAnywhere, Category = "GameData | GameData")
	FName GameNameKey;

	UPROPERTY(EditAnywhere, Category = "GameData | GameData")
	FGameData GameDataReference;

	bool ReceiveGameData();
	//==============================

	////////////////////////////////
	// Player‚ğ¶¬AŠi”[‚µ‚ÄCPU‚Ìl”‚ğŒˆ‚ß‚é
public:

protected:
	UPROPERTY(VisibleAnywhere, Category = "GameData | PlayerList")
	TArray<APlayerController*> PlayerList;

	UPROPERTY(VisibleAnywhere, Category = "GameData | PlayerList")
	int32 CPUNum;

	void CreateAttendance();
	//==============================
};
