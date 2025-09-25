#include "GameManager.h"
#include "Nob.h"
#include "Boyz.h"
#include "Warboss.h"

GameManager::GameManager()
	: CurrentStage(1),                // 1���������� �ʱ�ȭ
	State(GameState::MainMenu),     // ���� �޴� ���·� �ʱ�ȭ
	Enemy(nullptr),                 // �� ������ �ʱ�ȭ
	Trader(nullptr)                 // ���� ������ �ʱ�ȭ
{
	printf("[GameManager] : Ȳ������ ��ȣ�Ͻñ�.\n");
}

void GameManager::StartGame() 
{
	CurrentStage = 1;       
    // �������� 1�� �ʱ�ȭ
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

	printf("\n=== WH40k Malum Caedo ===\n");
	printf("������ �����մϴ�!\n");
	ShowMainMenu(); // ù ������(���� �޴�) ȣ��
}

void GameManager::ShowMainMenu() 
{
	State = GameState::MainMenu;
	int Choice = 0;

	while (true) {
		printf("\n===== ���� �޴� =====\n");
		printf("1. ���� ����\n");
		printf("2. �� ���� ����\n");
		printf("3. ���� ��ü (����/ü�μҵ�)\n");
		printf("����(��ȣ �Է�): ");

		std::cin >> Choice;

		if (Choice == 1) {
            InitStage(CurrentStage); // ���⼭ ù �������� �ʱ�ȭ
			StartBattle();
			return;
		}
		else if (Choice == 2) {
			ShowPlayerInfo();
		}
		else if (Choice == 3) {
			ChangeWeapon();
		}
		else {
			printf("�ùٸ� ��ȣ�� �Է��ϼ���.\n");
		}
	}
}


void GameManager::StartBattle()
{
	State = GameState::InBattle;
	
	player.ViewStatus();

	// ���� ����: �÷��̾�� ���� ��� ������� �� �ݺ�
	while (player.IsAlive() && Enemy && Enemy->IsAlive()) {
		// �� �� �� ü�� ǥ��
		if (Enemy) 
		{
			Enemy->ViewStatus();
		}

		// �÷��̾� �ൿ ������
		ShowBattleMenu();

		// ���� �����ϱ� ���� ���� ����ִ��� �ٽ� �˻�
		if (Enemy && Enemy->IsAlive() && player.IsAlive()) 
		{
			Enemy->Attack(player);
		}
	}

	// ���� ���� �� ���� ��ȯ �� ��� ó��
	State = GameState::AfterBattle;
	if (player.IsAlive()) 
	{
		EndBattle(true);  // �¸�
	}
	else 
	{
		EndBattle(false); // �й�
	}
}

void GameManager::ShowBattleMenu()
{
    int Choice = 0;
    bool ValidInput = false;

    while (!ValidInput) {
        printf("\n===== ���� �޴� =====\n");
        printf("1. ����\n");
        printf("2. �޵�ī�� ���\n");
        printf("3. ���� ��ü\n");
        printf("4. �� ���� ����\n");
        printf("����(��ȣ �Է�): ");

        std::cin >> Choice;

        if (Choice == 1) {
            player.Attack(*Enemy);
            ValidInput = true;
        }
        else if (Choice == 2) {
            UseMedi();
        }
        else if (Choice == 3) {
            ChangeWeapon();
        }
        else if (Choice == 4) {
            ShowPlayerInfo();
        }
        else {
            printf("�ùٸ� ��ȣ�� �Է��ϼ���.\n");
        }
    }
}

void GameManager::EndBattle(bool Victory)
{
    if (Victory) 
	{
        printf("\n�������� �¸��߽��ϴ�!\n");
        GiveLoot(); // ����ǰ ����
        if (IsVictoryConditionMet()) 
		{
            GameVictory(); // ���� Ŭ����
        } 
        else 
		{
            ShowAfterBattleMenu(); // ���� �� ������ �޴� ȣ��
        }
    } 
	else 
	{
        GameDefeat(); // ���� ���� ó��
    }

    
}

void GameManager::ShowAfterBattleMenu()
{
    int Choice = 0;
    bool ExitMenu = false;

    while (!ExitMenu)
    {
        printf("\n===== ���� �� �޴� =====\n");
        printf("1. �� ���� ����\n");
        printf("2. �޵�ī�� ���\n");
        printf("3. ���� �������� ���� (���� �������� : %d)\n", (CurrentStage + 1));
		printf("4. ���� ��ü (����/ü�μҵ�)\n");
        printf("����(��ȣ �Է�): ");
    
        std::cin >> Choice;

        if (Choice == 1)
        {
            ShowPlayerInfo();
        }
        else if (Choice == 2)
        {
            UseMedi();
        }
        else if (Choice == 3)
        {
            ExitMenu = true;
            MoveToNextStage();
        }
        else if (Choice == 4)
        {
            ChangeWeapon();
		}
        else
        {
            printf("�ùٸ� ��ȣ�� �Է��ϼ���.\n");
        }
    }
}

void GameManager::MoveToNextStage()
{
    ++CurrentStage;

    if (CurrentStage > TotalStages)
    {
        State = GameState::GameClear;
        GameVictory();
        return;
    }

    InitStage(CurrentStage);

    if (CurrentStage == 3 || CurrentStage == 6 || CurrentStage == 9)
    {
        State = GameState::TraderStage;
        ShowTraderMenu();
    }
    else if (CurrentStage == 8)
    {
        SetupEnemy(CurrentStage); // �� ����
        State = GameState::InBattle;
        StartBattle();
    }
    else if (CurrentStage == 12)
    {
        SetupEnemy(CurrentStage); // ���Ǿ� ����
        State = GameState::InBattle;
        StartBattle();
    }
    else
    {
        SetupEnemy(CurrentStage); // �Ϲ� ��(Boyz) ����
        State = GameState::InBattle;
        StartBattle();
    }
}

void GameManager::ShowTraderMenu()
{
    int Choice = 0;
    bool ExitMenu = false;

    printf("\n===== ���� �޴� =====\n");
    printf("������ �������ϴ�. �޵�ī��(����)�� ������ �� �ֽ��ϴ�.\n");

    while (!ExitMenu)
    {
        printf("1. �޵�ī�� ����\n");
        printf("2. �� ���� ����\n");
        printf("3. ���� ���������� �̵� (���� �������� : %d)\n", (CurrentStage + 1));
        printf("����(��ȣ �Է�): ");

        std::cin >> Choice;

        if (Choice == 1)
        {
            BuyMedi();
        }
        else if (Choice == 2)
        {
            ShowPlayerInfo();
        }
        else if (Choice == 3)
        {
            ExitMenu = true;
            MoveToNextStage();
        }
        else
        {
            printf("�ùٸ� ��ȣ�� �Է��ϼ���.\n");
        }
    }
}

void GameManager::ShowPlayerInfo()
{
    player.ViewStatus();
}

void GameManager::ChangeWeapon()
{
    player.SwapWeapon();
    if (player.MyWeapon == WeaponType::Bolter)
    {
        printf("\n���⸦ ���ͷ� ��ü�߽��ϴ�.\n");
		printf("���ʹ� ���Ÿ� �����, 3���� ����� �����ϰ�, 20~40�� ���ظ� �ݴϴ�.\n");
    }
    else if (player.MyWeapon == WeaponType::ChainSword)
    {
        printf("\n���⸦ ü�μҵ�� ��ü�߽��ϴ�.\n");
		printf("ü�μҵ�� ���� �����, 5���� ���� 10~20�� ���ظ� �ݴϴ�.\n");
    }
}

void GameManager::UseMedi()
{
    player.UsingMed();
}

void GameManager::BuyMedi()
{
    if (Trader != nullptr)
    {
        bool result = player.BuyMed(*Trader);
    }
    else
    {
        printf("�����ε�\n");
    }
}

void GameManager::GameVictory()
{
    printf("\n�����մϴ�! ���Ǿ��� óġ�ϰ� WH40k Malum Caedo�� Ŭ�����߽��ϴ�!\n");
    printf("For the Emperor!\n");
    printf("������ �����մϴ�.\n");
    exit(0);
}

void GameManager::GameDefeat()
{
    printf("\n�÷��̾ ����߽��ϴ�...\n");
    printf("WH40k Malum Caedo - �й�\n");
    printf("������ �����մϴ�.\n");
    exit(0);
}

int GameManager::GetCurrentStage() const
{
    return CurrentStage;
}

GameState GameManager::GetState() const
{
	return State;
}

void GameManager::InitStage(int StageNum)
{
    // ���� ��/���� ��ü ����
    if (Enemy != nullptr)
    {
        delete Enemy;
        Enemy = nullptr;
    }
    if (Trader != nullptr)
    {
        delete Trader;
        Trader = nullptr;
    }

    // ��/���� ��ġ
    if (StageNum == 3 || StageNum == 6 || StageNum == 9)
    {
        SetupTrader(StageNum);
    }
    else
    {
        SetupEnemy(StageNum);
    }
}

void GameManager::SetupEnemy(int StageNum)
{
    if (Enemy != nullptr)
    {
        delete Enemy;
        Enemy = nullptr;
    }

    if (StageNum == 8)
    {
        Enemy = new Nob();
        printf("\n===== ���� ����! =====\n");
        printf("\n�߰����� ���� ���� �����߽��ϴ�!\n");
    }
    else if (StageNum == 12)
    {
        Enemy = new Warboss();
        printf("\n===== ���� ����! =====\n");
        printf("\n�������� ���� ���Ǿ��� �����߽��ϴ�!\n");
    }
    else if (StageNum >= 1)
    {
        Enemy = new Boyz();
        printf("\n===== ���� ����! =====\n");
        printf("\n�� ���� ����� �����߽��ϴ�!\n");
    }
}

void GameManager::SetupTrader(int StageNum)
{
    if (Trader != nullptr)
    {
        delete Trader;
        Trader = nullptr;
    }

    Trader = new RougeTrader();
    // �ȳ� �޽����� ShowTraderMenu()������ ���
}

bool GameManager::IsVictoryConditionMet() const
{
    // ���� ��������(12)���� �� óġ �� Ŭ����
    return (CurrentStage == 12 && Enemy != nullptr && !Enemy->IsAlive());
}

void GameManager::GiveLoot()
{
    // ���� ��������(3, 6, 9)�� 12�������������� OaksHead�� �������� ����
    if (CurrentStage != 12 && CurrentStage != 3 && CurrentStage != 6 && CurrentStage != 9)
    {
        player.OaksHead++;
        printf("����ǰ: ���� �Ӹ��� 1���� ȹ���߽��ϴ�!\n\n");
    }
}
