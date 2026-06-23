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
	void ApplyDamage(float DamageAmount); // 밖에서는 데미지 양만 던져주면 됨
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float HP = 100.f; // HP도 컴포넌트가 스스로 들고 있게 합니다.
};