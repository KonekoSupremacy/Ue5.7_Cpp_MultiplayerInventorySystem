// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Fragment/Cpp_ItemFragment.h"

FItemFragment::FItemFragment() {
}

FGameplayTag FItemFragment::GetFragmentTag() const {
	return FragmentTag;
}

void FItemFragment::SetFragmentTag(const FGameplayTag& InTag) {
	FragmentTag = InTag;
}
