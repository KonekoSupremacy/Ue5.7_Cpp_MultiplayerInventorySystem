// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Cpp_PC_Inventory.generated.h"

class UInputAction;
// Forward declarations
class UInputMappingContext;

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
	virtual void SetupInputComponent() override;
	
	 void PrimaryInteract();
		
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TObjectPtr<UInputAction> PrimaryInteractAction;
};
