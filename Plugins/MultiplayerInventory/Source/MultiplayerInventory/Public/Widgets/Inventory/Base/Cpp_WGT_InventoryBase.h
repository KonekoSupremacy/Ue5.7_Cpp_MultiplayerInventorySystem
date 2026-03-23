// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Cpp_GridTypes.h"
#include "Cpp_WGT_InventoryBase.generated.h"

// Forward Declarations
class UCpp_AC_Item;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_InventoryBase : public UUserWidget {
	GENERATED_BODY()
	
		
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual FSlotAvailabilityResult DoesHaveRoomForItem(UCpp_AC_Item* ItemComp) const;
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
};
