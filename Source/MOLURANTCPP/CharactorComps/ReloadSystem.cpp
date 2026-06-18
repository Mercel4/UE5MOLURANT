#include "CharactorComps/ReloadSystem.h"

// Sets default values for this component's properties
UReloadSystem::UReloadSystem()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UReloadSystem::DoReload(int32& CurrentBullet, int32& MaxMagazineBullet, int32& CurrentReserveBullet, float ReloadTime)
{
	// currentBullet: 현재 탄창에 남은 총알 수
	// maxMagazineBullet: 현재 캐릭터가 가진 탄창의 최대 용량
	// currentReserveBullet: 현재 캐릭터가 가진 예비 총알 수
	// reloadTime: 재장전 시간
	
	if (bIsReloading) return false;
	
	if (IsAbleToReload(CurrentBullet, MaxMagazineBullet, CurrentReserveBullet))
	{
		bIsReloading = true;
		
		TargetCurrentBullet = &CurrentBullet;
		TargetMaxMagazineBullet = &MaxMagazineBullet;
		TargetCurrentReserveBullet = &CurrentReserveBullet;
		
		if (GetWorld())
		{
			GetWorld()->GetTimerManager().SetTimer(
				ReloadTimerHandle,
				this,
				&UReloadSystem::CompleteReload,
				ReloadTime,
				false
			);
		}
		
		return true;
	}
	
	
	
	return false;
}

bool UReloadSystem::IsAbleToReload(int32 CurrentBullet, int32 MaxMagazineBullet, int32 CurrentReserveBullet)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("CurrentBullet: %d, MaxMagazineBullet: %d, CurrentReserveBullet: %d"), CurrentBullet, MaxMagazineBullet, CurrentReserveBullet));
	return (CurrentBullet < MaxMagazineBullet) && (CurrentReserveBullet > 0);
}

void UReloadSystem::CompleteReload()
{
	if (!TargetCurrentBullet || !TargetMaxMagazineBullet || !TargetCurrentReserveBullet) 
	{
		bIsReloading = false;
		return;
	}

	// 포인터를 역참조(*)하여 블루프린트에 있는 원본 변수 값을 직접 수정합니다.
	int32 BulletNeeded = *TargetMaxMagazineBullet - *TargetCurrentBullet;

	if (*TargetCurrentReserveBullet >= BulletNeeded)
	{
		*TargetCurrentReserveBullet -= BulletNeeded;
		*TargetCurrentBullet = *TargetMaxMagazineBullet;
	}
	else
	{
		*TargetCurrentBullet += *TargetCurrentReserveBullet;
		*TargetCurrentReserveBullet = 0;
	}

	bIsReloading = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Reload Complete"));
}