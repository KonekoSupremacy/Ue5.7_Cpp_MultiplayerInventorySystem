// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Inventory/Base/Cpp_WGT_InventoryBase.h"
#include "Cpp_WGT_SpatialInventory.generated.h"

// Forward declarations
class UButton;
class UWidgetSwitcher;
class UCpp_WGT_InventoryGrid;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_SpatialInventory : public UCpp_WGT_InventoryBase {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual FSlotAvailabilityResult DoesHaveRoomForItem(UCpp_AC_Item* ItemComp) const override;
	
protected:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UFUNCTION(BlueprintCallable)
	void SetActiveGrid(UCpp_WGT_InventoryGrid* Grid, const UButton* ClickedButton);
	void DisableButton(const UButton* Button);
	
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryGrid> WBP_GridEquippables;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryGrid> WBP_GridConsumables;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryGrid> WBP_GridCraftables;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> WS_Grid;
	
	UPROPERTY(BlueprintReadWrite, Category="Inventory")
	TArray<TObjectPtr<UButton>> AllSwitcherButtons;
};
