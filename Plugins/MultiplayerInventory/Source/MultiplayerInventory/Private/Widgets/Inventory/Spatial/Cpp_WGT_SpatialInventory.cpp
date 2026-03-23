// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Cpp_WGT_SpatialInventory.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Widgets/Inventory/Spatial/Cpp_WGT_InventoryGrid.h"


FSlotAvailabilityResult UCpp_WGT_SpatialInventory::DoesHaveRoomForItem(UCpp_AC_Item* ItemComp) const {
	return FSlotAvailabilityResult();
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
