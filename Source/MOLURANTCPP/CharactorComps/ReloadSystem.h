#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReloadSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOLURANTCPP_API UReloadSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReloadSystem();
	
	UFUNCTION(BlueprintCallable, Category = "Reload")
	void DoReload(UPARAM(ref) int32& CurrentBullet, UPARAM(ref) int32& maxMagazineBullet, UPARAM(ref) int32& currentReserveBullet, float reloadTime);
	
private:
	bool IsAbleToReload(int32 CurrentBullet, int32 MaxMagazineBullet, int32 CurrentReserveBullet);
    
	// 타이머가 끝났을 때 실제 값을 바꾸는 함수
	void CompleteReload(); 

	FTimerHandle ReloadTimerHandle;

	// 블루프린트에서 넘겨받은 원본 변수들의 주소를 잠시 보관할 포인터들
	int32* TargetCurrentBullet = nullptr;
	int32* TargetMaxMagazineBullet = nullptr;
	int32* TargetCurrentReserveBullet = nullptr;

	bool bIsReloading = false;
};
