#include "EnemyComps/GetDamage.h"

UGetDamage::UGetDamage()
{ PrimaryComponentTick.bCanEverTick = false; }

// GetDamage.cpp
float UGetDamage::ApplyDamage(float DamageAmount)
{
	HP -= DamageAmount;
    
	if (HP <= 0.f)
	{
		HP = 0.f;
	}
	return HP;
}