#pragma once

#include "CoreMinimal.h"
#include "Types/Cpp_GridTypes.h"

#include "Cpp_InventoryManifest.generated.h"

/**
 * contains all requried data for creating new inv item
 */

USTRUCT()
struct MULTIPLAYERINVENTORY_API FCpp_InventoryManagement {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UCpp_InventoryItem* CreateNewItem(UObject* NewOuter);
	
	FORCEINLINE EItemCategory GetItemCategory(EItemCategory Category) const { return ItemCategory; }
	
private:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditAnywhere, Category = "Inventory")
	EItemCategory ItemCategory = EItemCategory::None;
};
