// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Cpp_AC_Inventory.generated.h"


class UCpp_WGT_InventoryBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MULTIPLAYERINVENTORY_API UCpp_AC_Inventory : public UActorComponent {
	GENERATED_BODY()

public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UCpp_AC_Inventory();

protected:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual void BeginPlay() override;

	void ConstructInventory();
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UCpp_WGT_InventoryBase> InventoryMenuClass;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UCpp_WGT_InventoryBase> InventoryMenu;
	
};
