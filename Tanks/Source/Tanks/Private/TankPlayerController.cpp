// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"

#include "TankPlayerController.h"
#include "../Public/TankPlayerController.h"


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing %s"), *(ControlledTank->GetName()));
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;//Out Parameter
	//FVector LookDirection = ;
	//If it hits landscape
	if (GetSiteRayHitLocation(HitLocation))//Has raytrace effect
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		
		
			//TODO Tell controlled tank to aim at this point
	}
}
//Getworld location through linetraceing through crosshair
bool ATankPlayerController::GetSiteRayHitLocation(FVector& HitLocation) const 
{
	//find/set crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize( ViewportSizeX,  ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	//*De-project the screen position of the crosshair to a world direction

	//line trace along that look direction, and see what is hit (up to max range)
	return true;
}
