#include "Items/Manifest/Cpp_InventoryManifest.h"

#include "Items/Cpp_InventoryItem.h"

UCpp_InventoryItem* FCpp_InventoryManagement::CreateNewItem(UObject* NewOuter) {
	UCpp_InventoryItem* NewItem = NewObject<UCpp_InventoryItem>(NewOuter,  UCpp_InventoryItem::StaticClass());
	return  NewItem;
}