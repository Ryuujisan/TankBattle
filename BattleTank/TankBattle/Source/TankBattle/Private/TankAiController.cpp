// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

ATank * ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		return nullptr;
	}

	return Cast<ATank>(PlayerPawn);
}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();


	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controler Dont find!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai ControllerBeginPlay: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAiController::GetControlledTabk() const
{
	return Cast<ATank>(GetPawn());
}

