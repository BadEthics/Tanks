// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"

#include "TankAIController.h"
#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
	    UE_LOG(LogTemp, Warning, TEXT("AIController cant find player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank())
	{
		//TODO Move towards player

		//Start aiming towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	
	return Cast<ATank>(PlayerPawn);
}