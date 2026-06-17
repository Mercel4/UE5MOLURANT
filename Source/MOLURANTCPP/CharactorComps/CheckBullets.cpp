// Fill out your copyright notice in the Description page of Project Settings.


#include "CharactorComps/CheckBullets.h"

UCheckBullets::UCheckBullets()
{
	PrimaryComponentTick.bCanEverTick = false;
}

int32 UCheckBullets::DoShoot(int32 CurrentBullets)
{
	if (CurrentBullets > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Able to Shoot"));
		CurrentBullets--;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Not Able to Shoot"));
	}

	return CurrentBullets;
}