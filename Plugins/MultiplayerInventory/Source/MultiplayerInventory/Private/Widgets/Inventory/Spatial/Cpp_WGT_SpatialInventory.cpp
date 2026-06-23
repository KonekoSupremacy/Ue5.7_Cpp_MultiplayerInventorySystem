// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Cpp_WGT_SpatialInventory.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "InventoryManagement/Cpp_BFL_InventoryStatics.h"
#include "Widgets/Inventory/Spatial/Cpp_WGT_InventoryGrid.h"


FSlotAvailabilityResult UCpp_WGT_SpatialInventory::DoesHaveRoomForItem(UCpp_AC_Item* ItemComp) const {
	FSlotAvailabilityResult Result;
	switch (UCpp_BFL_InventoryStatics::GetItemCategoryFromItemComp(ItemComp)) {
	case EItemCategory::None:
		UE_DEBUG_BREAK(); // why did this trigger?
		break;
	case EItemCategory::Equippable:
		return WBP_GridEquippables->HasRoomForItem(ItemComp);
	case EItemCategory::Consumable:
		return WBP_GridConsumables->HasRoomForItem(ItemComp);
	case EItemCategory::Craftable:
		return WBP_GridCraftables->HasRoomForItem(ItemComp);
	}
	Result.TotalAmountToFill = 1;
	return Result;
}

void UCpp_WGT_SpatialInventory::SetActiveGrid(UCpp_WGT_InventoryGrid* Grid, const UButton* ClickedButton) {
	DisableButton(ClickedButton);
	
	WS_Grid->SetActiveWidget(Grid);
}

void UCpp_WGT_SpatialInventory::DisableButton(const UButton* Button) {
	for (auto& Btn : AllSwitcherButtons) {
		Btn->SetIsEnabled(Btn != Button);
	}
}
