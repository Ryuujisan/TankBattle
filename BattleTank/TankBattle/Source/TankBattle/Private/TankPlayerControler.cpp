// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"


void ATankPlayerControler::BeginPlay()
{
	Super::BeginPlay();


	auto ControlledTank = GetControlledTabk();
	
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controler Dont find!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControllerBeginPlay: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerControler::GetControlledTabk() const
{
	return Cast<ATank>(GetPawn());
}


