// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RayCastComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOLURANTCPP_API URayCastComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URayCastComponent();
	
	UFUNCTION(BlueprintCallable, Category="Charactor")
	AActor* PerformRayCast(const FVector& WorldLocation, const FVector& ForwardVector, float distance);
};
