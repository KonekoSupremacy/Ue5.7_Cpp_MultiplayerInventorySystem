#include "InventoryManagement/FastArray/Cpp_InventoryFastArray.h"

#include "Items/Cpp_InventoryItem.h"

TArray<UCpp_InventoryItem> FInventoryFastArray::GetAllItems() const {
	return TArray<UCpp_InventoryItem>();
}

void FInventoryFastArray::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize) {
}

void FInventoryFastArray::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize) {
}

UCpp_InventoryItem* FInventoryFastArray::AddEntry(UCpp_AC_Inventory* ItemComponent) {
	return nullptr;
}

UCpp_InventoryItem* FInventoryFastArray::AddEntry(UCpp_InventoryItem* Item) {
	return nullptr;
}

void FInventoryFastArray::RemoveEntry(UCpp_InventoryItem* Item) {
}

bool FInventoryFastArray::NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms) {
	return FastArrayDeltaSerialize<FInventoryEntry, FInventoryFastArray>(Entries, DeltaParms, *this);
}
