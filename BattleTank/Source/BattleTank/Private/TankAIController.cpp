// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


	void ATankAIController::BeginPlay()
	{
		Super::BeginPlay();

		auto tank = GetControlledTank();
		auto pTank = GetPlayerTank();


		if (!tank)
		{
			UE_LOG(LogTemp, Warning, TEXT("AI: Nessun tank controllato."));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AI: Tank controllato: %s"), *(tank->GetName()));
		}

		if (!pTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("AI: Nessun player tank trovato."));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AI: il player tank è: %s"), *(pTank->GetName()));
		}



	}

	void ATankAIController::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		//UE_LOG(LogTemp, Warning, TEXT("P1 ticking."));
		AimTowardPlayerTank();

	}

	void  ATankAIController::AimTowardPlayerTank()
	{
		if (!GetControlledTank()) { return; }
		if (GetPlayerTank()) 
		{		
			FVector HitLocation = GetPlayerTank()->GetActorLocation();
			GetControlledTank()->AimAt(HitLocation);
		}


	}




	ATank* ATankAIController::GetControlledTank() const
	{
		return Cast<ATank>(GetPawn());
	}

	ATank* ATankAIController::GetPlayerTank() const
	{
		return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
