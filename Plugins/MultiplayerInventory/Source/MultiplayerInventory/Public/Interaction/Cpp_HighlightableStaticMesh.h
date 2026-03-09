// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cpp_HighlightInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Cpp_HighlightableStaticMesh.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERINVENTORY_API
	UCpp_HighlightableStaticMesh : public UStaticMeshComponent,  public ICpp_HighlightInterface {
	GENERATED_BODY()

public:
	//=================================================================================================================
	// FUNCTIONS
	//=================================================================================================================
	
	// Inherited From ICpp_HighlightInterface
	//=============================================
	virtual void Highlight_Implementation(const bool bHighlight) override;
	//=============================================
	
protected:
	//=================================================================================================================
	// PROPERTIES & VARIABLES
	//==================================================================================================================
	UPROPERTY(EditAnywhere, Category="Inventory")
	TObjectPtr<UMaterialInterface> HighlightMaterial;
};
