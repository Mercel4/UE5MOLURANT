#include "CharactorComps/GetDamage.h"

UGetDamage::UGetDamage()
{ PrimaryComponentTick.bCanEverTick = false; }

void UGetDamage::DamageTaken(float DamageAmount, float& HP)
{
	HP -= DamageAmount;
	if (HP < 0.f)
	{
		HP = 0.f;
	}
}
