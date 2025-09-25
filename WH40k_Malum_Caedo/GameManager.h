#pragma once
#include <iostream>
#include "Character.h"
#include "Nob.h"
#include "Boyz.h"
#include "Warboss.h"
#include "Player.h"
#include "RougeTrader.h"

enum class GameState {
	MainMenu,        // ���� ���� ������
	InBattle,        // ���� ��
	AfterBattle,     // ���� �� ������
	TraderStage,   // ���� ������ ��������
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
	bool IsVictoryConditionMet() const;
	void GiveLoot();                      // ����ǰ ����
};