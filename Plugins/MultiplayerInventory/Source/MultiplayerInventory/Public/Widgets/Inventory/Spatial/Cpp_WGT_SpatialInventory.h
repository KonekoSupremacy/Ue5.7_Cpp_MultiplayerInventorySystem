// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Inventory/Base/Cpp_WGT_InventoryBase.h"
#include "Cpp_WGT_SpatialInventory.generated.h"

// Forward declarations
class UWidgetSwitcher;
class UCpp_WGT_InventoryGrid;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_SpatialInventory : public UCpp_WGT_InventoryBase {
	GENERATED_BODY()
	
protected:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryGrid> WBP_GridEquippables;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryGrid> WBP_GridConsumables;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryGrid> WBP_GridCraftables;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> WS_Grid;
};
