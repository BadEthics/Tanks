// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tanks.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h" //MUST be the last include

/**
 * 
 */
UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	void AimTowardsCrosshair();//Start tank moving barrel so that a shot would hit where the crosshair interacts with the world
	bool GetSiteRayHitLocation(FVector& HitLocation) const;//Return out parameter, true if hit landscape


};
