// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankTurret.h"


void UTankTurret::Turn(float RelativeSpeed)
{
	//Move the barrel the right amount this frame

	//Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto YawChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewYaw = RelativeRotation.Pitch + YawChange;
	SetRelativeRotation(FRotator(0, 0, YawChange));
}
