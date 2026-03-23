#pragma once

#include "Cpp_GridTypes.generated.h"

class UCpp_InventoryItem;

UENUM(BlueprintType)
enum class EItemCategory : uint8 {
	None,
	Equippable,
	Consumable,
	Craftable,
};

USTRUCT()
struct FSlotAvailability {
	GENERATED_BODY()
	
	FSlotAvailability() {};
	FSlotAvailability(const int16 InIndex, const int16 InAmount, const bool bInItemAtIndex) {
		Index = InIndex;
		AmountToFill = InAmount;
		bItemAtIndex = bInItemAtIndex;
	}
	
	int16 Index = -1;
	int16 AmountToFill = 0;
	bool bItemAtIndex = false;
};

USTRUCT()
struct FSlotAvailabilityResult {
	GENERATED_BODY()
	
	FSlotAvailabilityResult() {};
	
	UPROPERTY()
	TWeakObjectPtr<UCpp_InventoryItem> Item;
	
	int16 TotalAmountToFill = 0;
	int16 Remaining = 0;
	
	bool bStackable = false;
	
	TArray<FSlotAvailability> AvailableSlots;
};