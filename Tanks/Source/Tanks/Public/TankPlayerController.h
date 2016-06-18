// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tanks.h"

#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h" //MUST be the last include

//Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	


private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();//Start tank moving barrel so that a shot would hit where the crosshair interacts with the world
	bool GetSiteRayHitLocation(FVector& HitLocation) const;//Return out parameter, true if hit landscape

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
