// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Cpp_PC_Inventory.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API ACpp_PC_Inventory : public APlayerController {
	GENERATED_BODY()
	
protected:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual void BeginPlay() override;
};
