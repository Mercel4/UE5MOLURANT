// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CheckBullets.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOLURANTCPP_API UCheckBullets : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCheckBullets();
	
	UFUNCTION(BlueprintCallable, Category="Charactor")
	void DoShoot(int32 CurrentBullets);
};
