#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WasDead.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOLURANTCPP_API UWasDead : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWasDead();
	
	UFUNCTION(BlueprintCallable, Category = "Components|WasDead")
	bool IsDead(float HP);
		
};
