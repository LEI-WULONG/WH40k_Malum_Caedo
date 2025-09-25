#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
	: CurrentStage(1),                // 1���������� �ʱ�ȭ
	State(GameState::MainMenu),     // ���� �޴� ���·� �ʱ�ȭ
	Enemy(nullptr),                 // �� ������ �ʱ�ȭ
	Trader(nullptr)                 // ���� ������ �ʱ�ȭ
{
	printf("[GameManager] ���� �������� : \n", CurrentStage);
}

void GameManager::StartGame() {
	CurrentStage = 1;               // �������� 1�� �ʱ�ȭ
	State = GameState::MainMenu;    // ���� �޴� ���·� �ʱ�ȭ

	// �÷��̾� �ʱ�ȭ (�ʿ��ϴٸ� �̸�, ���� �� �߰� ����)
	player = Player();              // �⺻ ������ ���, �߰� ���� ����

	// ��/���� ������ �ʱ�ȭ
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

	// ù �������� �ʱ�ȭ
	InitStage(CurrentStage);

	printf("=== WH40k Malum Caedo ===\n");
	printf("������ �����մϴ�!\n");
	ShowMainMenu(); // ù ������(���� �޴�) ȣ��
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
