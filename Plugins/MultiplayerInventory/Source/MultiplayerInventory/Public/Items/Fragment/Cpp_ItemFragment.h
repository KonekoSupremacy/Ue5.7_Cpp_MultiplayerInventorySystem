// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Cpp_ItemFragment.generated.h"

USTRUCT()
struct FItemFragment {
	GENERATED_BODY()
	
	FItemFragment() {};
	FItemFragment(const FItemFragment&) = default;
	FItemFragment& operator=(const FItemFragment&) = default;
	FItemFragment(FItemFragment&&) = default;
	FItemFragment& operator=(FItemFragment&&) = default;
	virtual ~FItemFragment() {}
	
	
	FORCEINLINE FGameplayTag GetFragmentTag() const { return FragmentTag; }
	FORCEINLINE void SetFragmentTag(const FGameplayTag& InTag) { FragmentTag = InTag; }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};


USTRUCT(BlueprintType)
struct FGridItemFragment : public FItemFragment {
	GENERATED_BODY()

	FORCEINLINE FIntPoint GetGridSize() const { return GridSize; }
	void SetGridSize(const FIntPoint& InGridSize) { GridSize = InGridSize; }
	FORCEINLINE float GetGridPadding() const { return GridPadding; }
	void SetGridPadding(float InGridPadding) { GridPadding = InGridPadding; }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FIntPoint GridSize{1, 1};
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float GridPadding = 0.f;
};