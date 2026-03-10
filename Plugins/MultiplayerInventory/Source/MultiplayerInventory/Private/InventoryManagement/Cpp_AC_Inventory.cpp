// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagement/Cpp_AC_Inventory.h"


UCpp_AC_Inventory::UCpp_AC_Inventory() {
	PrimaryComponentTick.bCanEverTick = false;

}


void UCpp_AC_Inventory::BeginPlay() {
	Super::BeginPlay();

	ConstructInventory();
}

void UCpp_AC_Inventory::ConstructInventory() {
}


