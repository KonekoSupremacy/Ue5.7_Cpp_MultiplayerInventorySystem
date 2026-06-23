// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagement/Cpp_BFL_InventoryStatics.h"

#include "InventoryManagement/Cpp_AC_Inventory.h"
#include "Items/Components/Cpp_AC_Item.h"

UCpp_AC_Inventory* UCpp_BFL_InventoryStatics::GetInventoryComponent(const APlayerController* PlayerController) {
	if (!IsValid(PlayerController)) {
		return nullptr;
	}
	auto* InventoryComponent = PlayerController->FindComponentByClass<UCpp_AC_Inventory>();
	checkf(InventoryComponent, TEXT("Null in %S"), __FUNCTION__);
	return InventoryComponent;
}

EItemCategory UCpp_BFL_InventoryStatics::GetItemCategoryFromItemComp(const UCpp_AC_Item* ItemComp) {
	if (!IsValid(ItemComp)) {
		return EItemCategory::None;
	}
	return ItemComp->GetItemManifest().GetItemCategory();
}
