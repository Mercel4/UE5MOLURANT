#include "Enemy.h"
#include "AIController.h"

AEnemy::AEnemy() { PrimaryActorTick.bCanEverTick = true; }
void AEnemy::BeginPlay() { Super::BeginPlay(); }
void AEnemy::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AEnemy::EnemyMoveToTarget(AActor* Target)
{
	if (Target)
	{
		AAIController* AIController = Cast<AAIController>(GetController());
		if (AIController)
		{
			AIController->MoveToActor(Target, -1.0f, true, true, false, 0, true);
		}
	}
}