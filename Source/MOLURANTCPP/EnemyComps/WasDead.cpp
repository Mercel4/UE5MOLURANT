#include "EnemyComps/WasDead.h"

UWasDead::UWasDead()
{ PrimaryComponentTick.bCanEverTick = false; }

bool UWasDead::IsDead(float HP)
{
	return HP <= 0.f;
}