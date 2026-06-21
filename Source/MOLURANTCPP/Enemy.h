#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class AAIController;

UCLASS()
class MOLURANTCPP_API AEnemy : public ACharacter
{
	GENERATED_BODY()
	
public:	
	AEnemy();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Enemy")
	void MoveToActor(AActor* TargetActor, float Speed);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float AcceptanceRadius = 5.0f;
	
private:
	UPROPERTY()
	AActor* CachedTargetActor = nullptr;
	
	float MoveSpeed = 0.0f;
	bool bIsMoving = false;
};
