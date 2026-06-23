#include "CharactorComps/GetDamage.h"

UGetDamage::UGetDamage()
{ PrimaryComponentTick.bCanEverTick = false; }

// GetDamage.cpp
void UGetDamage::ApplyDamage(float DamageAmount)
{
	HP -= DamageAmount;
    
	if (HP <= 0.f)
	{
		HP = 0.f;
		AActor* Owner = GetOwner(); // 이 컴포넌트가 붙어있는 '적 액터'를 가져옴
		if (Owner)
		{
			Owner->Destroy(); // 적 스스로 자결
		}
	}
}