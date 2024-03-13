#pragma once

#include "CoreMinimal.h"
#include "OthelloPieceColor.generated.h"

UENUM(BlueprintType)
enum class EOthelloPieceColor : uint8
{
	NONE = 0 UMETA(DisplayName = "NONE"),
	BLACK = 1 UMETA(DisplayName = "BLACK"),
	WHITE = 2 UMETA(DisplayName = "WHITE"),
};