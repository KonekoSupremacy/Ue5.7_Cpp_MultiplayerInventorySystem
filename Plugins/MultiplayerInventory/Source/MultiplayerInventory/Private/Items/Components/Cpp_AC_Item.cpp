// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Components/Cpp_AC_Item.h"

#include "Net/UnrealNetwork.h"


UCpp_AC_Item::UCpp_AC_Item() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UCpp_AC_Item::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ThisClass, ItemManifest);
}


