#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"

#include "Cpp_InventoryFastArray.generated.h"

class UCpp_AC_Inventory;
class UCpp_InventoryItem;

// single entry in inventory
USTRUCT()
struct FInventoryEntry : public FFastArraySerializerItem {
	GENERATED_BODY()
	
	FInventoryEntry() {}
	
private:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	friend UCpp_InventoryItem;
	friend struct FInventoryFastArray;
	
	UPROPERTY()
	TObjectPtr<UCpp_InventoryItem> Item = nullptr;
};


USTRUCT()
struct FInventoryFastArray : public FFastArraySerializer {
	GENERATED_BODY()
	
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	FInventoryFastArray() {
		OwnerComponent = nullptr;
	}
	FInventoryFastArray(UActorComponent* InOwnerComponent) {
		OwnerComponent = InOwnerComponent;
	}
	
	TArray<UCpp_InventoryItem*> GetAllItems() const;
	
	// FFastArray funcs
	void PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms);
	
	UCpp_InventoryItem* AddEntry(UCpp_AC_Inventory* ItemComponent);
	UCpp_InventoryItem* AddEntry(UCpp_InventoryItem* Item);
	void RemoveEntry(UCpp_InventoryItem* Item);
	
private:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	void BroadcastEntry_Internal(const TArrayView<int32> Indices, const bool bRemoved);
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	friend UCpp_AC_Inventory; 
	
	UPROPERTY(NotReplicated)
	TObjectPtr<UActorComponent> OwnerComponent;
	
	UPROPERTY()
	TArray<FInventoryEntry> Entries;
};

template<>
struct TStructOpsTypeTraits<FInventoryFastArray> : public TStructOpsTypeTraitsBase2<FInventoryFastArray> {
	enum {
		WithNetDeltaSerializer = true
	};	
};