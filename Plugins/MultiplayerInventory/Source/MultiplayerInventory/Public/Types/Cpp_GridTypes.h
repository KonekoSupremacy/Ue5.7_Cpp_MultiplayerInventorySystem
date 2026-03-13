#pragma once

#include "Cpp_GridTypes.generated.h"

UENUM(BlueprintType)
enum class EItemCategory : uint8 {
	None,
	Equippable,
	Consumable,
	Craftable,
};