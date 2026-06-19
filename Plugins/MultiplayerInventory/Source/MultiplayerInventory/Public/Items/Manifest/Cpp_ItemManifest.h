#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Items/Fragment/Cpp_ItemFragment.h"
#include "StructUtils/InstancedStruct.h"
#include "Types/Cpp_GridTypes.h"

#include "Cpp_ItemManifest.generated.h"

/**
 * contains all requried data for creating new inv item
 */

USTRUCT()
struct MULTIPLAYERINVENTORY_API FCpp_ItemManifest {
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
	UPROPERTY(EditAnywhere, Category="Inventory", meta = (ExcludeBaseStruct))	
	TArray<TInstancedStruct<FItemFragment>> Fragments;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	EItemCategory ItemCategory = EItemCategory::None;
	
	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (Categories = "GameItems"))
	FGameplayTag ItemType;
};
