// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cpp_BFL_WidgetUtils.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API
	UCpp_BFL_WidgetUtils : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	
public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	static int32 GetIndexFromPosition(const FIntPoint& Position, const int16 Columns);
};
