// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"//last include

/**
 * 
 */



UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	//-1 is max downward movement, and +1 is max upward movement
	void Turn(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxYawDegrees = 360;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinYawDegrees = -360;
	
};
