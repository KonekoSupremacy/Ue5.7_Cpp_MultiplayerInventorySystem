// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Cpp_PC_Inventory.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Interaction/Cpp_HighlightInterface.h"
#include "InventoryManagement/Cpp_AC_Inventory.h"
#include "Items/Cpp_InventoryItem.h"
#include "Items/Components/Cpp_AC_Item.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/HUD/Cpp_WGT_HUD.h"

void ACpp_PC_Inventory::ToggleInventory() {
	if (!IsValid(InventoryComponent)) {
		return;
	}
	InventoryComponent->ToggleInventory();
}

void ACpp_PC_Inventory::BeginPlay() {
	Super::BeginPlay();
	
	InventoryComponent = FindComponentByClass<UCpp_AC_Inventory>();
	
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
	EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, &ACpp_PC_Inventory::PrimaryInteract);
	EnhancedInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Started, this, &ACpp_PC_Inventory::ToggleInventory);
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
	const AActor* PreviousHitActorRaw = PreviousHitActor.Get();
	CurrentHitActor = HitResult.GetActor();
	const AActor* CurrentHitActorRaw = HitResult.GetActor(); // non weak, faster lookup than weak
	if (!CurrentHitActorRaw) {
		if (IsValid(HUDWidget)) {
			HUDWidget->HidePickupMessage();
		}
	}
	// same as previous, ignore
	if (CurrentHitActorRaw == PreviousHitActorRaw) {
		return;
	}
	
	// Highlight New
	if (CurrentHitActor.IsValid()) {
		ToggleItemHighlight(CurrentHitActorRaw, true);
		
		const auto* ItemComponent = CurrentHitActorRaw->FindComponentByClass<UCpp_AC_Item>();
		if (!IsValid(ItemComponent)) {
			return;
		}
		if (IsValid(HUDWidget)) {
			HUDWidget->ShowPickupMessage(ItemComponent->GetPickupMessage());
		}
	}
	
	// Unhighlight Old
	if (IsValid(PreviousHitActorRaw)) {
		ToggleItemHighlight(PreviousHitActorRaw, false);
	}
}
void ACpp_PC_Inventory::ToggleItemHighlight(const AActor* InActor, const bool bHighlight) {
	if (auto* Highlightable = InActor->FindComponentByInterface(
	UCpp_HighlightInterface::StaticClass()); IsValid(Highlightable)) {
		ICpp_HighlightInterface::Execute_Highlight(Highlightable, bHighlight);
	}
}
void ACpp_PC_Inventory::PrimaryInteract() {
	UE_LOG(LogTemp, Warning, TEXT("Primary Interact"));
	auto* HitActor = CurrentHitActor.Get();
	if (!HitActor) {
		return;
	}
	auto* ItemComp = HitActor->FindComponentByClass<UCpp_AC_Item>();
	check(InventoryComponent);
	InventoryComponent->TryAddingItemToInventory(ItemComp);
}
