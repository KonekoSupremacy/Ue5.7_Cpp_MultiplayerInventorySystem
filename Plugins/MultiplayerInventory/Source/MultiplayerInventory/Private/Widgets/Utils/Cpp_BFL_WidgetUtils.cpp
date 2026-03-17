// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_BFL_WidgetUtils.h"

int32 UCpp_BFL_WidgetUtils::GetIndexFromPosition(const FIntPoint& Position, const int16 Columns) {
	return Position.Y * Columns + Position.X;
}
