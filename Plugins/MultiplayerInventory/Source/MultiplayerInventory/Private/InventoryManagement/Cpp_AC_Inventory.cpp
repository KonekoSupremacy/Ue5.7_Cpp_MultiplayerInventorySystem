// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagement/Cpp_AC_Inventory.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/Inventory/Base/Cpp_WGT_InventoryBase.h"


UCpp_AC_Inventory::UCpp_AC_Inventory() {
	PrimaryComponentTick.bCanEverTick = false;

}


void UCpp_AC_Inventory::BeginPlay() {
	Super::BeginPlay();

	ConstructInventory();
}

void UCpp_AC_Inventory::ConstructInventory() {
	OwningController = Cast<APlayerController>(GetOwner());
	auto* OwningControllerRaw = OwningController.Get();
	checkf(OwningControllerRaw, 
		TEXT("OwningController is not valid. Inventory component must be owned by a PlayerController."))
	
	if (!OwningController->IsLocalController()) {
		return;
	}
	
	InventoryWidget = CreateWidget<UCpp_WGT_InventoryBase>(OwningControllerRaw, InventoryWidgetClass);
	InventoryWidget->AddToViewport();
	
}


