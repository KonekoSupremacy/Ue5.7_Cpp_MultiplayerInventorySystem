// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Cpp_WGT_InventoryGrid.h"

#include "Components/UniformGridPanel.h"
#include "InventoryManagement/Cpp_AC_Inventory.h"
#include "InventoryManagement/Cpp_BFL_InventoryStatics.h"
#include "Items/Cpp_InventoryItem.h"
#include "Items/Components/Cpp_AC_Item.h"
#include "Items/Manifest/Cpp_ItemManifest.h"
#include "Widgets/GridSlots/Cpp_WGT_GridSlot.h"
#include "Widgets/Utils/Cpp_BFL_WidgetUtils.h"

FSlotAvailabilityResult UCpp_WGT_InventoryGrid::HasRoomForItem(const UCpp_AC_Item* ItemComp) {
	return HasRoomForItem(ItemComp->GetItemManifest());
}

void UCpp_WGT_InventoryGrid::AddItem(UCpp_InventoryItem* Item, bool bRemoved) {
	if (bRemoved) {
		return;
	}
	if (!MatchesCategory(Item)) {
		return; 
	}
	
	FSlotAvailabilityResult Result = HasRoomForItem(Item);
}

void UCpp_WGT_InventoryGrid::NativeOnInitialized() {
	Super::NativeOnInitialized();
	
	ConstructGrid();
	
	InventoryComponent = UCpp_BFL_InventoryStatics::GetInventoryComponent(GetOwningPlayer());
	InventoryComponent->OnItemUpdated.AddDynamic(this, &ThisClass::AddItem);
}

void UCpp_WGT_InventoryGrid::ConstructGrid() {
	GridSlots.Reserve(GridRowCount * GridColumnCount);
	for (int16 Row = 0; Row < GridRowCount; Row++) {
		for (int16 Col = 0; Col < GridColumnCount; Col++) {
			UCpp_WGT_GridSlot* GridSlot = CreateWidget<UCpp_WGT_GridSlot>(this, GridSlotClass);
			GridPanel->AddChildToUniformGrid(GridSlot ,Row, Col);

			const int16 Index = UCpp_BFL_WidgetUtils::GetIndexFromPosition(FIntPoint(Row, Col), GridColumnCount);
			GridSlot->InitGridSlot(Index, GridSlotSize);
		}
	}
}

bool UCpp_WGT_InventoryGrid::MatchesCategory(const UCpp_InventoryItem* Item) const {
	return Item->GetItemManifest().GetItemCategory() == GetItemCategory();
}

FSlotAvailabilityResult UCpp_WGT_InventoryGrid::HasRoomForItem(const UCpp_InventoryItem* Item) {
	return HasRoomForItem(Item->GetItemManifest());
}
FSlotAvailabilityResult UCpp_WGT_InventoryGrid::HasRoomForItem(const FCpp_ItemManifest& Item) {
	FSlotAvailabilityResult Result;
	Result.TotalAmountToFill = 1;
	return Result;
}
