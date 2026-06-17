#include "MOLURANTCPPGameMode.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

AMOLURANTCPPGameMode::AMOLURANTCPPGameMode()
{
    CurrentRoundTime = 0;
    SavedInGamePhaseTime = 0;
    CurrentRound = 1;
    CurrentPhase = EGamePhase::BuyPhase;
}

void AMOLURANTCPPGameMode::StartMatchRules(float BuyPhaseDuration, float InGamePhaseDuration, int32 TotalRounds)
{
    SavedInGamePhaseTime = FMath::FloorToInt(InGamePhaseDuration);
    MaxRounds = TotalRounds;

    CurrentPhase = EGamePhase::BuyPhase;
    CurrentRoundTime = FMath::FloorToInt(BuyPhaseDuration);

    // 타이머 핵심 메소드
    GetWorldTimerManager().SetTimer(
       RoundTimerHandle,
       this,
       &AMOLURANTCPPGameMode::CountdownRound,
       1.0f,
       true
    );
}

void AMOLURANTCPPGameMode::CountdownRound()
{
    if (CurrentRoundTime > 0) CurrentRoundTime--;
    else // 0초가 되었을 때
    {
        switch (CurrentPhase)
        {
            case EGamePhase::BuyPhase:
                // 구매 단계 0초 -> 전투 시작!
                SwitchToInGamePhase();
                break;

            case EGamePhase::InGamePhase:
                // 전투 단계 0초 -> 라운드 종료 정산 시작!
                EndRound();
                break;
            
            case EGamePhase::RoundEnd:
                // 정산 단계 5초가 흐르고 0초가 되었을 때! ➔ 다음 라운드 진입!
                CurrentRound++;
                
                if (CurrentRound <= MaxRounds)
                {
                    // 아직 최대 라운드가 안 끝났다면 새로운 구매 단계로 돌입!
                    SwitchToBuyPhase();
                }
                else
                {
                    // 모든 라운드가 끝났다면 타이머를 완전히 종료
                    GetWorldTimerManager().ClearTimer(RoundTimerHandle);
                }
                break;
        }
    }
}

void AMOLURANTCPPGameMode::SwitchToInGamePhase()
{
    CurrentPhase = EGamePhase::InGamePhase;
    CurrentRoundTime = SavedInGamePhaseTime;
    
    OnPhaseChanged.Broadcast(CurrentPhase);
}

// 다음 라운드 구매 단계로 넘어갈 때의 처리
void AMOLURANTCPPGameMode::SwitchToBuyPhase()
{
    CurrentPhase = EGamePhase::BuyPhase;
    
    CurrentRoundTime = 5;
    OnPhaseChanged.Broadcast(CurrentPhase);
}

// 전투 단계가 끝났을 때 (0초가 되었을 때)
void AMOLURANTCPPGameMode::EndRound()
{
    CurrentPhase = EGamePhase::RoundEnd;
    CurrentRoundTime = 5; // 5초 동안 카운트다운 진행
    OnPhaseChanged.Broadcast(CurrentPhase);
}

FText AMOLURANTCPPGameMode::GetFormatedRoundTime() const
{
    int32 Minutes = CurrentRoundTime / 60;
    int32 Seconds = CurrentRoundTime % 60;
    return FText::FromString(FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds));
}

FText AMOLURANTCPPGameMode::GetFormatedCurrentRound() const
{
    return FText::FromString(FString::Printf(TEXT("ROUND %02d ////// DEFENDER"), CurrentRound));
}