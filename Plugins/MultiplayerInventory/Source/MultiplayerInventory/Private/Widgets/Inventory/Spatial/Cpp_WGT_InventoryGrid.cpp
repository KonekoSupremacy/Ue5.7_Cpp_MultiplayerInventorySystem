// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Cpp_WGT_InventoryGrid.h"

#include "Components/UniformGridPanel.h"
#include "Widgets/GridSlots/Cpp_WGT_GridSlot.h"
#include "Widgets/Utils/Cpp_BFL_WidgetUtils.h"

void UCpp_WGT_InventoryGrid::NativeOnInitialized() {
	Super::NativeOnInitialized();
	
	ConstructGrid();
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
