// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Cpp_PC_Inventory.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/HUD/Cpp_WGT_HUD.h"

void ACpp_PC_Inventory::BeginPlay() {
	Super::BeginPlay();
	
	auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(Subsystem)) {
		for (auto DefaultMappingContext : DefaultMappingContexts) {
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	CreateHudWidget();
}

void ACpp_PC_Inventory::SetupInputComponent() {
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, 
		&ACpp_PC_Inventory::PrimaryInteract);
}

void ACpp_PC_Inventory::PrimaryInteract() {
	UE_LOG(LogTemp, Warning, TEXT("Primary Interact"));
}

void ACpp_PC_Inventory::CreateHudWidget() {
	if (!IsLocalController()) { // no need for dedicated server
		return;
	}
	
	checkf(HUDWidgetClass, TEXT("HUDWidgetClass is nullptr! Please assign HUDWidgetClass for PC"));
	HUDWidget = CreateWidget<UCpp_WGT_HUD>(this, HUDWidgetClass);
	if (IsValid(HUDWidget)) {
		HUDWidget->AddToViewport();
	}
}
