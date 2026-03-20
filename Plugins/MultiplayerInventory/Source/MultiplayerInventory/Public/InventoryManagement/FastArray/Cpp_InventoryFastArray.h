#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"

#include "Cpp_InventoryFastArray.generated.h"

class UCpp_InventoryItem;

// single entry in inventory
USTRUCT()
struct FInventoryEntry : public FFastArraySerializerItem {
	GENERATED_BODY()
	
	FInventoryEntry() {}
	
private:
	friend UCpp_InventoryItem;
	friend struct FInventoryFastArray;
	
	UPROPERTY()
	TObjectPtr<UCpp_InventoryItem> Item = nullptr;
};


USTRUCT()
struct FInventoryFastArray : public FFastArraySerializer {
	GENERATED_BODY()
	
};