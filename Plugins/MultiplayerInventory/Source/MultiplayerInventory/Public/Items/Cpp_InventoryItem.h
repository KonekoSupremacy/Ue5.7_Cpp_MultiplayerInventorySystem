// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/InstancedStruct.h"
#include "UObject/Object.h"
#include "Cpp_InventoryItem.generated.h"
// Forward Declarations
struct FCpp_InventoryManifest;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_InventoryItem : public UObject {
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	void SetItemManifest(const FCpp_InventoryManifest& Manifest);
private:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(VisibleAnywhere, Replicated, meta = (BaseStruct ="/Script/Inventory.Cpp_InventoryManifest"), Category = "Inventory")
	FInstancedStruct ItemManifest;
};
