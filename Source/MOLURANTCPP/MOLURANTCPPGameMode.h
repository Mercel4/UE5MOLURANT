#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MOLURANTCPPGameMode.generated.h"

UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	BuyPhase      UMETA(DisplayName = "Buy Phase"),
	InGamePhase   UMETA(DisplayName = "In Game Phase"),
	RoundEnd      UMETA(DisplayName = "Round End")
};

UCLASS()
class AMOLURANTCPPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMOLURANTCPPGameMode();
    
	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void StartMatchRules(float BuyPhaseDuration, float InGamePhaseDuration, int32 TotalRounds);

	UFUNCTION(BlueprintPure, Category = "GameMode")
	FText GetFormatedRoundTime() const;
	
	UFUNCTION(BlueprintCallable, Category = "GameMode")
	FText GetFormatedCurrentRound() const;

protected:
	void CountdownRound();
	void SwitchToInGamePhase(); // 구매 단계 -> 전투 단계 전환 함수
	void EndRound();            // 전투 단계 -> 라운드 종료 함수
	void SwitchToBuyPhase();	// 라운드 종료 -> 구매 단계

	UPROPERTY(BlueprintReadOnly, Category = "GameMode")
	int32 CurrentRoundTime;

	// 데이터를 기억해둘 저장용 변수들
	int32 SavedInGamePhaseTime;
	int32 MaxRounds;
	int32 CurrentRound;

	// 현재 무슨 단계인지 기억하는 변수
	EGamePhase CurrentPhase;

	FTimerHandle RoundTimerHandle;
};