// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Cpp_PC_Inventory.generated.h"

class UCpp_AC_Inventory;
// Forward declarations
class UInputMappingContext;
class UInputAction;
class UCpp_WGT_HUD;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API ACpp_PC_Inventory : public APlayerController {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UFUNCTION(BlueprintCallable)
	void ToggleInventory();
	
protected:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;
	
	void CreateHudWidget();
	
	void TraceForItem();
	static void ToggleItemHighlight(const AActor* InActor, const bool bHighlight);
	void PrimaryInteract();
	
		
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY()
	TObjectPtr<UCpp_AC_Inventory> InventoryComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TArray<TObjectPtr<UInputMappingContext>> DefaultMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TObjectPtr<UInputAction> PrimaryInteractAction;
	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Input") 
	TObjectPtr<UInputAction> ToggleInventoryAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory|UI")
	TSubclassOf<UCpp_WGT_HUD> HUDWidgetClass;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UCpp_WGT_HUD> HUDWidget;
	
	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	float InteractionTraceLength = 1000.f;
	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;
	
	UPROPERTY()
	TWeakObjectPtr<AActor> CurrentHitActor;
	UPROPERTY()
	TWeakObjectPtr<AActor> PreviousHitActor;
};

