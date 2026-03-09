// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Cpp_HighlightableStaticMesh.h"

void UCpp_HighlightableStaticMesh::Highlight_Implementation(
	const bool bHighlight) {
	checkf(HighlightMaterial, TEXT("Please update Highlight Material for Highlightable Static Mesh!"));
	SetOverlayMaterial(bHighlight ? HighlightMaterial : nullptr);
}
