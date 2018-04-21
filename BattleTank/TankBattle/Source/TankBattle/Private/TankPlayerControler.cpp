// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"


void ATankPlayerControler::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerControler::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector Hitlocation; // Out Parament

	if (GetSightRayHitLocation(Hitlocation))
	{

		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *Hitlocation.ToString());
		//GetWorld location id lintrace thrugh crosshair
		//if it hits the landscapr
		//tell controlled;
	}
}

bool ATankPlayerControler::GetSightRayHitLocation(FVector & OUTHitFector) const
{
	int32 VieportSizex, vieportSizeY;

	GetViewportSize(VieportSizex, vieportSizeY);

	auto ScreanLocation = FVector2D(VieportSizex * CrosshairXLocation, vieportSizeY * CrosshairYLocation);
	FVector LookDirection;
	
	if (GetLookDirection(ScreanLocation, LookDirection))
	{
		if (GetLookVector(LookDirection, OUTHitFector))
		{
			return true;
		}
	}

	return true;
}

bool ATankPlayerControler::GetLookDirection(FVector2D ScreanLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreanLocation.X, 
		ScreanLocation.Y, 
		CameraWorldLocation, 
		LookDirection);
}

bool ATankPlayerControler::GetLookVector(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
		//Set hit location and return true
	}

	HitLocation = FVector(0.0);
	return false;
}

void ATankPlayerControler::BeginPlay()
{
	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();
	
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controler Dont find!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControllerBeginPlay: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


