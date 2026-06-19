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

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Enemy")
	void EnemyMoveToTarget(AActor* TargetActor);
	
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	float MoveSpeed = 500.0f;
	

public:	
	virtual void Tick(float DeltaTime) override;
};
