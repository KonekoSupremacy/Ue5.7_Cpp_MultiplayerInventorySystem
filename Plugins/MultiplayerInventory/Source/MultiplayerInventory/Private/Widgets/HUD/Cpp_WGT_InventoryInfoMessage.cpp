// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HUD/Cpp_WGT_InventoryInfoMessage.h"

#include "Components/TextBlock.h"

void UCpp_WGT_InventoryInfoMessage::ShowMessage_Implementation(const FString& Message) {
	check(TXT_Message);
	TXT_Message->SetText(FText::FromString(Message));
	
	bIsMessageActive = true;
	if (MessageHideTimerHandle.IsValid()) {
		MessageHideTimerHandle.Invalidate();
	}
	GetWorld()->GetTimerManager().SetTimer(MessageHideTimerHandle, [this]() {
		HideMessage();
		bIsMessageActive = false;
	}, MessageDuration, false);
}
