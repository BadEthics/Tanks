// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "Tank.h"
#include "../Public/TankPlayerController.h"






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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
};

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;//Out Parameter
	//If it hits landscape
	if (GetSiteRayHitLocation(HitLocation))//Has raytrace effect
	{
		GetControlledTank()->AimAt(HitLocation); // Tell controlled tank to aim at this point
	}
}

//Getworld location through linetraceing through crosshair
bool ATankPlayerController::GetSiteRayHitLocation(FVector& HitLocation) const 
{
	//find crosshair position in pixel coords
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize( ViewportSizeX,  ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//*De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//line trace along that look direction, and see what is hit (up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	
	return true;
}

//*De-project the screen position of the crosshair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;//to be discarded

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		) 
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0.0f);
	return false;//line trace didnt work
}
