// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cpp_BFL_InventoryStatics.generated.h"

class UCpp_AC_Inventory;
/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_BFL_InventoryStatics : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UFUNCTION(BlueprintPure, Category = "Inventory")
	static UCpp_AC_Inventory* GetInventoryComponent(const APlayerController* PlayerController);
};
