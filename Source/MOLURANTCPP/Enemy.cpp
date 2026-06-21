#include "Enemy.h"

AEnemy::AEnemy() { PrimaryActorTick.bCanEverTick = true; }
void AEnemy::BeginPlay() { Super::BeginPlay(); }

void AEnemy::MoveToActor(AActor* TargetActor, float Speed)
{
	if (!TargetActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MoveToActor: TargetActor가 nullptr입니다."));
		return;
	}
	
	CachedTargetActor = TargetActor;
	MoveSpeed = Speed;
	bIsMoving = true;
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!bIsMoving || !CachedTargetActor) return;
	
	const FVector CurrentLocation = GetActorLocation();
	const FVector TargetLocation = CachedTargetActor->GetActorLocation();
	const float DistanceToTarget = FVector::Dist(CurrentLocation, TargetLocation);

	if (DistanceToTarget <= AcceptanceRadius)
	{
		SetActorLocation(TargetLocation);
		bIsMoving = false;
		return;
	}
	
	const FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	const FVector NewLocation = CurrentLocation + Direction * MoveSpeed * DeltaTime;

	SetActorLocation(NewLocation);
}
