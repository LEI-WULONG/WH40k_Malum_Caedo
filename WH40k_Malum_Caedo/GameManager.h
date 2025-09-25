#pragma once
#include <vector>
#include "Player.h"
#include "Character.h"
#include "RougeTrader.h"   // 상인
#include "WarBoss.h"       // 중간/최종 보스

enum class GameState {
	MainMenu,        // 게임 시작 선택지
	InBattle,        // 전투 중
	AfterBattle,     // 전투 후 선택지
	MerchantStage,   // 상인 만나는 스테이지
	GameClear,       // 게임 클리어
	GameOver         // 패배
};

class GameManager {
public:
	GameManager();
	

	void StartGame();                // 게임 시작 및 초기화
	void ShowMainMenu();             // 게임 시작 선택지
	void StartBattle();              // 전투 시작
	void ShowBattleMenu();           // 전투 중 선택지
	void EndBattle(bool Victory);    // 전투 후 처리
	void ShowAfterBattleMenu();      // 전투 후 선택지
	void MoveToNextStage();          // 다음 스테이지 진행
	void ShowTraderMenu();         // 상인 스테이지 선택지
	void ShowPlayerInfo();           // 내 정보 보기
	void ShowEnemyInfo();            // 적 정보 보기
	void ChangeWeapon();             // 무기 교체
	void UseMedi();               // 메디카에 사용
	void BuyMedi();               // 상인에게 힐템 구매
	void GameVictory();              // 게임 승리
	void GameDefeat();               // 게임 패배

	int GetCurrentStage() const;
	GameState GetState() const;

private:
	static constexpr int TotalStages = 12;
	int CurrentStage;
	GameState State;
	Player player;
	Character* Enemy;
	RougeTrader* Trader;

	void InitStage(int StageNum);         // 스테이지 초기화
	void SetupEnemy(int StageNum);        // 적 배치 (중간/최종 보스)
	void SetupTrader(int StageNum);     // 상인 배치 (3, 6, 9)
	bool IsTraderStage(int StageNum) const;
	bool IsBossStage(int StageNum) const;
	bool IsVictoryConditionMet() const;
	void GiveLoot();                      // 전리품 지급
	void HandleInput(int MenuChoice);     // 선택지 처리
};