#include "Items/Manifest/Cpp_ItemManifest.h"

#include "Items/Cpp_InventoryItem.h"

UCpp_InventoryItem* FCpp_ItemManifest::CreateNewItem(UObject* NewOuter) {
	UCpp_InventoryItem* NewItem = NewObject<UCpp_InventoryItem>(NewOuter,  UCpp_InventoryItem::StaticClass());
	NewItem->SetItemManifest(*this);
	return  NewItem;
}