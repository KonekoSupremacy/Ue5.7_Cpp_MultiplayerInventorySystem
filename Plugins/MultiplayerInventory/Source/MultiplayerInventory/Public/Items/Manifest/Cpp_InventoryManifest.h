#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/Cpp_GridTypes.h"

#include "Cpp_InventoryManifest.generated.h"

/**
 * contains all requried data for creating new inv item
 */

USTRUCT()
struct MULTIPLAYERINVENTORY_API FCpp_InventoryManifest {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UCpp_InventoryItem* CreateNewItem(UObject* NewOuter);
	
	FORCEINLINE EItemCategory GetItemCategory() const { return ItemCategory; }
	FORCEINLINE FGameplayTag GetItemType() const { return ItemType; }
	
private:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditAnywhere, Category = "Inventory")
	EItemCategory ItemCategory = EItemCategory::None;
	
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (Categories = "GameItems"))
	FGameplayTag ItemType;
};
