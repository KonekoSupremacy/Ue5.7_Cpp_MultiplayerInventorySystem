// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Cpp_ItemFragment.generated.h"

USTRUCT()
struct FItemFragment {
	GENERATED_BODY()
	
	FItemFragment();
	FItemFragment(const FItemFragment&) = default;
	FItemFragment& operator=(const FItemFragment&) = default;
	FItemFragment(FItemFragment&&) = default;
	FItemFragment& operator=(FItemFragment&&) = default;
	virtual ~FItemFragment() {}
	
	
	FGameplayTag GetFragmentTag() const;
	void SetFragmentTag(const FGameplayTag& InTag);
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};