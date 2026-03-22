// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HUD/Cpp_WGT_HUD.h"

#include "InventoryManagement/Cpp_AC_Inventory.h"
#include "InventoryManagement/Cpp_BFL_InventoryStatics.h"
#include "Widgets/HUD/Cpp_WGT_InventoryInfoMessage.h"

void UCpp_WGT_HUD::NativeOnInitialized() {
	Super::NativeOnInitialized();

	UCpp_AC_Inventory* InventoryComp = UCpp_BFL_InventoryStatics::GetInventoryComponent(GetOwningPlayer());
	if (IsValid(InventoryComp)) {
		InventoryComp->OnInventoryFull.AddDynamic(this, &ThisClass::NoSpaceLeftInInventory);
	}
}

void UCpp_WGT_HUD::NoSpaceLeftInInventory() {
	check(WBP_InfoMessage);
	
	WBP_InfoMessage->ShowMessage(NSLOCTEXT("InventoryMessages", "NoSpaceInInventory", "No Space Left In Inventory!").ToString());
}
