// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cpp_FragmentTags.h"
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
	UPROPERTY(VisibleAnywhere, Category = "Inventory", meta = (Categories = "Fragment"))
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};


USTRUCT(BlueprintType, DisplayName = "Grid Fragment")
struct FGridItemFragment : public FItemFragment {
	GENERATED_BODY()

	FGridItemFragment() { SetFragmentTag(Fragment::Grid); }
	FORCEINLINE FIntPoint GetGridSize() const { return GridSize; }
	FORCEINLINE float GetGridPadding() const { return GridPadding; }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FIntPoint GridSize{1, 1};
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float GridPadding = 0.f;
};

USTRUCT(BlueprintType, DisplayName = "Icon Fragment")
struct FIconItemFragment : public FItemFragment {
	GENERATED_BODY()

	FIconItemFragment() { SetFragmentTag(Fragment::Icon); }
	FORCEINLINE UTexture2D* GetIcon() const { return Icon; }
	FORCEINLINE FVector2D GetDimensions() const { return Dimensions; }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UTexture2D> Icon = nullptr;
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FVector2D Dimensions{44.f, 44.f};
};