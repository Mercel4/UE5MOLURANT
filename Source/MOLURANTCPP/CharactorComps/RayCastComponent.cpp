// Fill out your copyright notice in the Description page of Project Settings.

#include "RayCastComponent.h"

URayCastComponent::URayCastComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

AActor* URayCastComponent::PerformRayCast(const FVector& StartLocation, const FVector& ForwardVector, float distance)
{
	FVector Start = StartLocation;
	FVector Forward = Start + (ForwardVector * distance);
	
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());
	
	bool bHit = GetWorld() -> LineTraceSingleByChannel(
		Hit,
		Start,
		Forward,
		ECC_Visibility,
		Params
	);
	
	if (bHit)
	{
		if (AActor* HitActor = Hit.GetActor())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit Actor: %s"), *HitActor->GetName()));
			
			// return AActor*
			return HitActor;
		}
	};
	
	return nullptr;
}
