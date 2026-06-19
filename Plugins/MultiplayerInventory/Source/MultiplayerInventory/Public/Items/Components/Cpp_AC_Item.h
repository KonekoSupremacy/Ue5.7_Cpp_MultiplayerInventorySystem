// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/Manifest/Cpp_ItemManifest.h"
#include "Cpp_AC_Item.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class MULTIPLAYERINVENTORY_API UCpp_AC_Item : public UActorComponent {
	GENERATED_BODY()

public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	UCpp_AC_Item();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	FORCEINLINE FString GetPickupMessage() const { return PickupMessage; }
	FORCEINLINE FCpp_ItemManifest GetItemManifest() const { return ItemManifest; }
	
	
protected:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//=================================================================================================================
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FString PickupMessage = "F -> Pickup Item";
	
	UPROPERTY(Replicated, EditAnywhere, Category = "Inventory")
	FCpp_ItemManifest ItemManifest;
};
