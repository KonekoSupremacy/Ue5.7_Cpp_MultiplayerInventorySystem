// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagement/Cpp_AC_Inventory.h"

#include "Blueprint/UserWidget.h"
#include "Net/UnrealNetwork.h"
#include "Widgets/Inventory/Base/Cpp_WGT_InventoryBase.h"


UCpp_AC_Inventory::UCpp_AC_Inventory() {
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);
	bReplicateUsingRegisteredSubObjectList = true;
}

void UCpp_AC_Inventory::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ThisClass, InventoryList);
}

void UCpp_AC_Inventory::ToggleInventory() {
	if (!IsValid(InventoryWidget)) {
		return;
	}
	bInventoryOpen = !bInventoryOpen;
	InventoryWidget->SetVisibility((bInventoryOpen) ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	if (auto* ControllerRaw = OwningController.Get()) {
		if (bInventoryOpen) {
			const FInputModeGameAndUI InputMode;
			ControllerRaw->SetInputMode(InputMode);
		}
		else {
			const FInputModeGameOnly InputMode;
			ControllerRaw->SetInputMode(InputMode);
		}
		ControllerRaw->SetShowMouseCursor(bInventoryOpen);
	}
}

void UCpp_AC_Inventory::AddReplicatedSubObj(UObject* SubObj) {
	if (IsUsingRegisteredSubObjectList() && IsReadyForReplication() && IsValid(SubObj)) {
		AddReplicatedSubObject(SubObj);
	}
}

void UCpp_AC_Inventory::TryAddingItemToInventory(UCpp_AC_Item* ItemComp) {
	FSlotAvailabilityResult Result = InventoryWidget->DoesHaveRoomForItem(ItemComp);
	if (Result.TotalAmountToFill == 0) {
		OnInventoryFull.Broadcast();
		return;
	}
	auto* Item = Result.Item.Get();
	if (Item && Result.bStackable) {
		// update stack count of existing item
		Server_AddStacksToItem(ItemComp, Result.TotalAmountToFill, Result.Remaining);
	}
	else if (Result.TotalAmountToFill > 0) {
		// create item slot
		const int16 StackCount = Result.bStackable ? Result.TotalAmountToFill : 0;
		Server_AddNewItemToInventory(ItemComp, StackCount);
	}
}


void UCpp_AC_Inventory::Server_AddNewItemToInventory_Implementation(UCpp_AC_Item* ItemComp, int16 StackCount) {
	auto* NewItem = InventoryList.AddEntry(ItemComp);
	check(NewItem);	
	
	
}
void UCpp_AC_Inventory::Server_AddStacksToItem_Implementation(UCpp_AC_Item* ItemComp, int16 StackCount, int16 Remaining) {
	
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
	bInventoryOpen = true;
	ToggleInventory(); // close it
}


