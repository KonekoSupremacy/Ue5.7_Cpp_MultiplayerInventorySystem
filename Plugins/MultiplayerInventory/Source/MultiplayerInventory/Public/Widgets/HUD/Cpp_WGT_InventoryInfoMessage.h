// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cpp_WGT_InventoryInfoMessage.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_InventoryInfoMessage : public UUserWidget {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintNativeEvent, Category="Inventory")
	void ShowMessage(const FString& Message);
	UFUNCTION(BlueprintImplementableEvent, Category="Inventory")
	void HideMessage();

private:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TXT_Message;
	
	UPROPERTY(EditAnywhere, Category="Inventory")
	float MessageDuration = 3.5f;
	
	FTimerHandle MessageHideTimerHandle;
	bool bIsMessageActive = false;
};
