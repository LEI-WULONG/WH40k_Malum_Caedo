#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
	: CurrentStage(1),                // 1스테이지로 초기화
	State(GameState::MainMenu),     // 메인 메뉴 상태로 초기화
	Enemy(nullptr),                 // 적 포인터 초기화
	Trader(nullptr)                 // 상인 포인터 초기화
{
	printf("[GameManager] 현재 스테이지 : \n", CurrentStage);
}

void GameManager::StartGame() {
	CurrentStage = 1;               // 스테이지 1로 초기화
	State = GameState::MainMenu;    // 메인 메뉴 상태로 초기화

	// 플레이어 초기화 (필요하다면 이름, 무기 등 추가 설정)
	player = Player();              // 기본 생성자 사용, 추가 설정 가능

	// 적/상인 포인터 초기화
	if (Enemy)
	{
		delete Enemy;
		Enemy = nullptr;
	}
	if (Trader)
	{
		delete Trader;
		Trader = nullptr;
	}

	// 첫 스테이지 초기화
	InitStage(CurrentStage);

	printf("=== WH40k Malum Caedo ===\n");
	printf("게임을 시작합니다!\n");
	ShowMainMenu(); // 첫 선택지(메인 메뉴) 호출
}

void GameManager::ShowMainMenu()
{
}

void GameManager::StartBattle()
{
}

void GameManager::ShowBattleMenu()
{
}

void GameManager::EndBattle(bool Victory)
{
}

void GameManager::ShowAfterBattleMenu()
{
}

void GameManager::MoveToNextStage()
{
}

void GameManager::ShowTraderMenu()
{
}

void GameManager::ShowPlayerInfo()
{
}

void GameManager::ShowEnemyInfo()
{
}

void GameManager::ChangeWeapon()
{
}

void GameManager::UseMedi()
{
}

void GameManager::BuyMedi()
{
}

void GameManager::GameVictory()
{
}

void GameManager::GameDefeat()
{
}

int GameManager::GetCurrentStage() const
{
	return 0;
}

GameState GameManager::GetState() const
{
	return GameState();
}

void GameManager::InitStage(int StageNum)
{
}

void GameManager::SetupEnemy(int StageNum)
{
}

void GameManager::SetupTrader(int StageNum)
{
}

bool GameManager::IsTraderStage(int StageNum) const
{
	return false;
}

bool GameManager::IsBossStage(int StageNum) const
{
	return false;
}

bool GameManager::IsVictoryConditionMet() const
{
	return false;
}

void GameManager::GiveLoot()
{
}

void GameManager::HandleInput(int MenuChoice)
{
}
