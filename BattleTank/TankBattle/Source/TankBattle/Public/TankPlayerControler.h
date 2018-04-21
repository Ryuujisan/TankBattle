// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControler.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerControler : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;

	virtual void Tick(float deltaTime) override;
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.333f;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	//Start The tank moving the barrel so that a shot would hit where
	//the crosshair intersecr the world
	void AimTowardsCrosshair();
	//Return a Out Parametr, true if hit landscape
	bool GetSightRayHitLocation(FVector& OUTHitFector) const;	
	bool GetLookDirection(FVector2D ScreanLocation, FVector & LookDirection) const;
	bool GetLookVector(FVector LookDirection, FVector& HitLocation) const;	
};
