// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Cpp_PC_Inventory.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
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

void ACpp_PC_Inventory::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	
	TraceForItem();
}

void ACpp_PC_Inventory::SetupInputComponent() {
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, 
		&ACpp_PC_Inventory::PrimaryInteract);
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

void ACpp_PC_Inventory::TraceForItem() {
	FVector2D ViewportCenter;
	{ // update center
		int32 ViewX, ViewY;
		GetViewportSize(ViewX, ViewY);
		ViewportCenter = FVector2D(ViewX, ViewY) / 2.f;
	}
	FVector TraceStart;
	FVector Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this,	ViewportCenter, TraceStart, Forward)) {
		return;
	}
	const FVector TraceEnd = TraceStart + (Forward * InteractionTraceLength);
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ItemTraceChannel);
	
	PreviousHitActor = CurrentHitActor;
	CurrentHitActor = HitResult.GetActor();
	if (CurrentHitActor.HasSameIndexAndSerialNumber(PreviousHitActor)) {
		return;
	}
	
	if (CurrentHitActor.IsValid()) {
		UE_LOG(LogTemp, Warning, TEXT("Trace New Actor"))
	}
	if (PreviousHitActor.IsValid()) {
		UE_LOG(LogTemp, Warning, TEXT("Stopped Tracing Actor"))
	}
}

void ACpp_PC_Inventory::PrimaryInteract() {
	UE_LOG(LogTemp, Warning, TEXT("Primary Interact"));
}
