#pragma once

#include "CoreMinimal.h"
#include "OthelloSquareType.generated.h"

UENUM()
enum class EOthelloSquareType : uint8
{
	NONE = 0 UMETA(DisplayName = "NONE"),
	BLACK = 1 UMETA(DisplayName = "BLACK"),
	WHITE = 2 UMETA(DisplayName = "WHITE"),
};