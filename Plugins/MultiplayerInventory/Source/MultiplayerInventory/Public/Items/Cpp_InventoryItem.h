// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manifest/Cpp_ItemManifest.h"
#include "StructUtils/InstancedStruct.h"
#include "UObject/Object.h"
#include "Cpp_InventoryItem.generated.h"

// Forward Declarations
struct FCpp_ItemManifest;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_InventoryItem : public UObject {
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override;
	
	FORCEINLINE const FCpp_ItemManifest& GetItemManifest() const { return ItemManifest.Get<FCpp_ItemManifest>(); }
	FORCEINLINE FCpp_ItemManifest& GetItemManifestMutable() { return ItemManifest.GetMutable<FCpp_ItemManifest>(); }
	void SetItemManifest(const FCpp_ItemManifest& Manifest);
	
private:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(VisibleAnywhere, Replicated, meta = (BaseStruct ="/Script/Inventory.Cpp_InventoryManifest"), Category = "Inventory")
	FInstancedStruct ItemManifest;
};

template <typename FragmentType>
const FragmentType* GetFragment(const UCpp_InventoryItem* Item, const FGameplayTag& Tag) {
	if (!IsValid(Item)) {
		return nullptr;
	}
	const FCpp_ItemManifest& Manifest = Item->GetItemManifest();
	return Manifest.GetFragmentOfTypeWithTag<FragmentType>(Tag);
}
