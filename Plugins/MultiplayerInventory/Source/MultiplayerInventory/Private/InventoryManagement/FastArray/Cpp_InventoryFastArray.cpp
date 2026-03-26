#include "InventoryManagement/FastArray/Cpp_InventoryFastArray.h"

#include "InventoryManagement/Cpp_AC_Inventory.h"
#include "Items/Cpp_InventoryItem.h"
#include "Items/Components/Cpp_AC_Item.h"

TArray<UCpp_InventoryItem*> FInventoryFastArray::GetAllItems() const {
	TArray<UCpp_InventoryItem*> Results;
	Results.Reserve(Entries.Num());
	for (const auto& Entry : Entries) {
		if (IsValid(Entry.Item)) {
			Results.Emplace(Entry.Item);
		}
	}
	return Results;
}

void FInventoryFastArray::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize) {
	BroadcastEntry_Internal(RemovedIndices, true);
}

void FInventoryFastArray::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize) {
	BroadcastEntry_Internal(AddedIndices, false);
}

UCpp_InventoryItem* FInventoryFastArray::AddEntry(const UCpp_AC_Item* ItemComponent) {
	check(OwnerComponent);
	auto* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority());
	
	auto* InventoryComp = Cast<UCpp_AC_Inventory>(OwnerComponent);
	check(InventoryComp);
	
	FInventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Item = ItemComponent->GetItemManifest().CreateNewItem(OwningActor);
	InventoryComp->AddReplicatedSubObj(NewEntry.Item);
	MarkItemDirty(NewEntry);
	return NewEntry.Item;
}

UCpp_InventoryItem* FInventoryFastArray::AddEntry(UCpp_InventoryItem* Item) {
	check(OwnerComponent);
	AActor* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority());
	
	FInventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Item = Item;
	MarkItemDirty(NewEntry);
	return Item;
}

void FInventoryFastArray::RemoveEntry(UCpp_InventoryItem* Item) {
	for  (int16 i = 0; i< Entries.Num(); i++) {
		if (Entries[i].Item == Item) {
			Entries.RemoveAt(i);
			MarkArrayDirty();
			return;
		}
	}
}

void FInventoryFastArray::BroadcastEntry_Internal(const TArrayView<int32> Indices, const bool bRemoved) {
	if (const auto* InventoryComp = Cast<UCpp_AC_Inventory>(OwnerComponent)) {
		for (const int32 Index : Indices) {
			InventoryComp->OnItemUpdated.Broadcast(Entries[Index].Item, bRemoved);
		}
	}
}

bool FInventoryFastArray::NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms) {
	return FastArrayDeltaSerialize<FInventoryEntry, FInventoryFastArray>(Entries, DeltaParms, *this);
}
