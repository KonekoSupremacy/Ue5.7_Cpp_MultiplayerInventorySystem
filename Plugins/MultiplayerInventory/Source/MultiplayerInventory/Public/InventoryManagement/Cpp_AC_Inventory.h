// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Cpp_AC_Inventory.generated.h"

class UCpp_InventoryItem;
// Forward Declarations
class UCpp_WGT_InventoryBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventoryItemUpdate, UCpp_InventoryItem*, Item, bool, bRemoved);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class MULTIPLAYERINVENTORY_API UCpp_AC_Inventory : public UActorComponent {
	GENERATED_BODY()

public:
	//=================================================================================================================
	// FUNCTIONS
	//====================================== ===========================================================================
	UCpp_AC_Inventory();
	
	void ToggleInventory();
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	FInventoryItemUpdate OnItemUpdated;

protected:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual void BeginPlay() override;

	void ConstructInventory();
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY()
	TWeakObjectPtr<APlayerController> OwningController;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UCpp_WGT_InventoryBase> InventoryWidgetClass;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UCpp_WGT_InventoryBase> InventoryWidget;

	bool bInventoryOpen = false;
};
