// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Cpp_WGT_SpatialInventory.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Widgets/Inventory/Spatial/Cpp_WGT_InventoryGrid.h"

void UCpp_WGT_SpatialInventory::NativeOnInitialized() {
	Super::NativeOnInitialized();
	
	BTN_Equippables->OnClicked.AddDynamic(this, &ThisClass::ShowEquippables);
	BTN_Consumables->OnClicked.AddDynamic(this, &ThisClass::ShowConsumables);
	BTN_Craftables->OnClicked.AddDynamic(this, &ThisClass::ShowCraftables);
}

void UCpp_WGT_SpatialInventory::ShowEquippables() {
}

void UCpp_WGT_SpatialInventory::ShowConsumables() {
}

void UCpp_WGT_SpatialInventory::ShowCraftables() {
}

void UCpp_WGT_SpatialInventory::SetActiveGrid(UCpp_WGT_InventoryGrid* Grid, UButton* ClickedButton) {
	DisableButton(ClickedButton);
	
	WS_Grid->SetActiveWidget(Grid);
}

void UCpp_WGT_SpatialInventory::DisableButton(UButton* Button) {
	BTN_Equippables->SetIsEnabled(true);
	BTN_Consumables->SetIsEnabled(true);
	BTN_Craftables->SetIsEnabled(false);
	Button->SetIsEnabled(false);
}
