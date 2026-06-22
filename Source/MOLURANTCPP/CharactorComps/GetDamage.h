#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GetDamage.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOLURANTCPP_API UGetDamage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGetDamage();
	
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void DamageTaken(float DamageAmount, UPARAM(ref)float& HP);
};
