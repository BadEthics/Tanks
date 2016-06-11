// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"

#include "TankPlayerController.h"
#include "../Public/TankPlayerController.h"


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking"));
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
	//If it hits landscape
	if (GetSiteRayHitLocation(HitLocation))//Has raytrace effect
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		
		
			//TODO Tell controlled tank to aim at this point
	}
}
//Getworld location through linetraceing through crosshair
bool ATankPlayerController::GetSiteRayHitLocation(FVector& HitLocation) const 
{
	HitLocation = FVector(1.0f);
	return true;
}
