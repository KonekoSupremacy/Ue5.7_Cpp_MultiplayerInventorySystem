#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StructUtils/InstancedStruct.h"
#include "Types/Cpp_GridTypes.h"

#include "Cpp_ItemManifest.generated.h"

/**
 * contains all requried data for creating new inv item
 */

// Forward Declarations
struct FItemFragment;

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
	
	template<typename T> requires std::derived_from<T, FItemFragment>
	const T* GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag);
	
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

template<typename T> requires std::derived_from<T, FItemFragment>
const T* FCpp_ItemManifest::GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag) {
	for (const TInstancedStruct<FItemFragment>& Fragment : Fragments) {
		if (const T* Frag = Fragment.GetPtr<T>()) {
			if (Frag->GetFragmentTag().MatchesTagExact(FragmentTag)) {
				return Frag;
			}
		}
		
	}
	return nullptr;
}
