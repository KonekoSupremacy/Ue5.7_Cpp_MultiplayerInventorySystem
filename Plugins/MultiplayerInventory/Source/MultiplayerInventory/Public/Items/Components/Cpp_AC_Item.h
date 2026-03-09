// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Cpp_AC_Item.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MULTIPLAYERINVENTORY_API UCpp_AC_Item : public UActorComponent {
	GENERATED_BODY()

public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UCpp_AC_Item();
	
	FORCEINLINE FString GetPickupMessage() const { return PickupMessage; }
	
protected:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FString PickupMessage;
};
