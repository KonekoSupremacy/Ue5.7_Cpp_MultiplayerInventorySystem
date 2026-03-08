// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Cpp_PC_Inventory.generated.h"

class UCpp_WGT_HUD;
// Forward declarations
class UInputMappingContext;
class UInputAction;

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
	void CreateHudWidget();
		
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TArray<TObjectPtr<UInputMappingContext>> DefaultMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TObjectPtr<UInputAction> PrimaryInteractAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory|UI")
	TSubclassOf<UCpp_WGT_HUD> HUDWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	 TObjectPtr<UCpp_WGT_HUD> HUDWidget;
};

