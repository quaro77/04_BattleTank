// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


	void ATankAIController::BeginPlay()
	{
		Super::BeginPlay();
		PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		ControlledTank = Cast<ATank>(GetPawn());

	}

	void ATankAIController::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		//UE_LOG(LogTemp, Warning, TEXT("P1 ticking."));
		
		

		if (PlayerTank)
		{
			FVector HitLocation = PlayerTank->GetActorLocation();
			ControlledTank->AimAt(HitLocation);
			//ControlledTank->Fire();
		}

	}




