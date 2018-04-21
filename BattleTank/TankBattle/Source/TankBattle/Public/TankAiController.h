// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework\Actor.h"
#include "Engine\World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTabk() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
};
