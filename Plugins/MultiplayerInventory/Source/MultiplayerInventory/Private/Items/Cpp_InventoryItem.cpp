// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Cpp_InventoryItem.h"

#include "Items/Manifest/Cpp_ItemManifest.h"
#include "Net/UnrealNetwork.h"

void UCpp_InventoryItem::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ThisClass, ItemManifest);
}

bool UCpp_InventoryItem::IsSupportedForNetworking() const {
	return true;
}

void UCpp_InventoryItem::SetItemManifest(const FCpp_ItemManifest& Manifest) {
	ItemManifest = FInstancedStruct::Make<FCpp_ItemManifest>(Manifest);
}
