// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
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
	ATank* GetControlledTabk() const;

	virtual void BeginPlay() override;
	
};
