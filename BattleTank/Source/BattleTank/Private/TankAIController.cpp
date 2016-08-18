// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
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
			UE_LOG(LogTemp, Warning, TEXT("AI: il player tank �: %s"), *(pTank->GetName()));
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