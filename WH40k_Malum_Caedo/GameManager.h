#pragma once
#include <vector>
#include "Player.h"
#include "Character.h"
#include "RougeTrader.h"   // ����
#include "WarBoss.h"       // �߰�/���� ����

enum class GameState {
	MainMenu,        // ���� ���� ������
	InBattle,        // ���� ��
	AfterBattle,     // ���� �� ������
	MerchantStage,   // ���� ������ ��������
	GameClear,       // ���� Ŭ����
	GameOver         // �й�
};

class GameManager {
public:
	GameManager();
	

	void StartGame();                // ���� ���� �� �ʱ�ȭ
	void ShowMainMenu();             // ���� ���� ������
	void StartBattle();              // ���� ����
	void ShowBattleMenu();           // ���� �� ������
	void EndBattle(bool Victory);    // ���� �� ó��
	void ShowAfterBattleMenu();      // ���� �� ������
	void MoveToNextStage();          // ���� �������� ����
	void ShowTraderMenu();         // ���� �������� ������
	void ShowPlayerInfo();           // �� ���� ����
	void ShowEnemyInfo();            // �� ���� ����
	void ChangeWeapon();             // ���� ��ü
	void UseMedi();               // �޵�ī�� ���
	void BuyMedi();               // ���ο��� ���� ����
	void GameVictory();              // ���� �¸�
	void GameDefeat();               // ���� �й�

	int GetCurrentStage() const;
	GameState GetState() const;

private:
	static constexpr int TotalStages = 12;
	int CurrentStage;
	GameState State;
	Player player;
	Character* Enemy;
	RougeTrader* Trader;

	void InitStage(int StageNum);         // �������� �ʱ�ȭ
	void SetupEnemy(int StageNum);        // �� ��ġ (�߰�/���� ����)
	void SetupTrader(int StageNum);     // ���� ��ġ (3, 6, 9)
	bool IsTraderStage(int StageNum) const;
	bool IsBossStage(int StageNum) const;
	bool IsVictoryConditionMet() const;
	void GiveLoot();                      // ����ǰ ����
	void HandleInput(int MenuChoice);     // ������ ó��
};