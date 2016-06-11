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
};
