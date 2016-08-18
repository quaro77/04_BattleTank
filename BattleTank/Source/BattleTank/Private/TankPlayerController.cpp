// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetControlledTank();

	if (!tank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("P1: Nessun tank controllato."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("P1: Tank controllato: %s"), *(tank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("P1 ticking."));
	AimTowardsCrosshair();

}




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void  ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank) { return;  }


}



