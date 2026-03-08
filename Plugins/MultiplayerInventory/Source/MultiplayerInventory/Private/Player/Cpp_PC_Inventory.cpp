// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Cpp_PC_Inventory.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ACpp_PC_Inventory::BeginPlay() {
	Super::BeginPlay();
	
	auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(Subsystem)) {
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
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
