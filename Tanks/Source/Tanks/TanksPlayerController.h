// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TanksPlayerController.generated.h"//must be the last include

/**
 * 
 */
UCLASS()
class TANKS_API ATanksPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	
};
