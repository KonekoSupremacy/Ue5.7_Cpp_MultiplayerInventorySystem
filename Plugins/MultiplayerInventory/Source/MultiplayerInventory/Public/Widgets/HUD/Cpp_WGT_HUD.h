// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cpp_WGT_HUD.generated.h"

class UCpp_WGT_InventoryInfoMessage;
/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_HUD : public UUserWidget {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ShowPickupMessage(const FString& Message);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void HidePickupMessage();
	
private:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UFUNCTION()
	void NoSpaceLeftInInventory();
	
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCpp_WGT_InventoryInfoMessage> WBP_InfoMessage;
	
};
