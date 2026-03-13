// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Cpp_GridTypes.h"
#include "Cpp_WGT_InventoryGrid.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_InventoryGrid : public UUserWidget {
	GENERATED_BODY()
	
protected:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	FORCEINLINE EItemCategory GetItemCategory() const { return ItemCategory; }
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory")
	EItemCategory ItemCategory; 	
};
