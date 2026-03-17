// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cpp_WGT_GridSlot.generated.h"

// Forward declarations
class UImage;

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API UCpp_WGT_GridSlot : public UUserWidget {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UFUNCTION(BlueprintNativeEvent, Category="Grid")
	void InitGridSlot(const int32 InIndex, const float Size);
	
protected:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> IMG_GridSlot;
	
	int16 Index;
	
};

