#include "GameManager.h"
#include "Nob.h"
#include "Boyz.h"
#include "Warboss.h"

GameManager::GameManager()
	: CurrentStage(1),                // 1스테이지로 초기화
	State(GameState::MainMenu),     // 메인 메뉴 상태로 초기화
	Enemy(nullptr),                 // 적 포인터 초기화
	Trader(nullptr)                 // 상인 포인터 초기화
{
	printf("[GameManager] : 황제님이 가호하시길.\n");
}

void GameManager::StartGame() 
{
	CurrentStage = 1;       
    // 스테이지 1로 초기화
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

	printf("\n=== WH40k Malum Caedo ===\n");
	printf("게임을 시작합니다!\n");
	ShowMainMenu(); // 첫 선택지(메인 메뉴) 호출
}

void GameManager::ShowMainMenu() 
{
	State = GameState::MainMenu;
	int Choice = 0;

	while (true) {
		printf("\n===== 메인 메뉴 =====\n");
		printf("1. 전투 시작\n");
		printf("2. 내 정보 보기\n");
		printf("3. 무기 교체 (볼터/체인소드)\n");
		printf("선택(번호 입력): ");

		std::cin >> Choice;

		if (Choice == 1) {
            InitStage(CurrentStage); // 여기서 첫 스테이지 초기화
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
			printf("올바른 번호를 입력하세요.\n");
		}
	}
}


void GameManager::StartBattle()
{
	State = GameState::InBattle;
	
	player.ViewStatus();

	// 전투 루프: 플레이어와 적이 모두 살아있을 때 반복
	while (player.IsAlive() && Enemy && Enemy->IsAlive()) {
		// 매 턴 적 체력 표시
		if (Enemy) 
		{
			Enemy->ViewStatus();
		}

		// 플레이어 행동 선택지
		ShowBattleMenu();

		// 적이 공격하기 전에 적이 살아있는지 다시 검사
		if (Enemy && Enemy->IsAlive() && player.IsAlive()) 
		{
			Enemy->Attack(player);
		}
	}

	// 전투 종료 후 상태 전환 및 결과 처리
	State = GameState::AfterBattle;
	if (player.IsAlive()) 
	{
		EndBattle(true);  // 승리
	}
	else 
	{
		EndBattle(false); // 패배
	}
}

void GameManager::ShowBattleMenu()
{
    int Choice = 0;
    bool ValidInput = false;

    while (!ValidInput) {
        printf("\n===== 전투 메뉴 =====\n");
        printf("1. 공격\n");
        printf("2. 메디카에 사용\n");
        printf("3. 무기 교체\n");
        printf("4. 내 정보 보기\n");
        printf("선택(번호 입력): ");

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
            printf("올바른 번호를 입력하세요.\n");
        }
    }
}

void GameManager::EndBattle(bool Victory)
{
    if (Victory) 
	{
        printf("\n전투에서 승리했습니다!\n");
        GiveLoot(); // 전리품 지급
        if (IsVictoryConditionMet()) 
		{
            GameVictory(); // 게임 클리어
        } 
        else 
		{
            ShowAfterBattleMenu(); // 전투 후 선택지 메뉴 호출
        }
    } 
	else 
	{
        GameDefeat(); // 게임 오버 처리
    }

    
}

void GameManager::ShowAfterBattleMenu()
{
    int Choice = 0;
    bool ExitMenu = false;

    while (!ExitMenu)
    {
        printf("\n===== 전투 후 메뉴 =====\n");
        printf("1. 내 정보 보기\n");
        printf("2. 메디카에 사용\n");
        printf("3. 다음 스테이지 진행 (다음 스테이지 : %d)\n", (CurrentStage + 1));
		printf("4. 무기 교체 (볼터/체인소드)\n");
        printf("선택(번호 입력): ");
    
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
            printf("올바른 번호를 입력하세요.\n");
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
        SetupEnemy(CurrentStage); // 놉 생성
        State = GameState::InBattle;
        StartBattle();
    }
    else if (CurrentStage == 12)
    {
        SetupEnemy(CurrentStage); // 워뽀쓰 생성
        State = GameState::InBattle;
        StartBattle();
    }
    else
    {
        SetupEnemy(CurrentStage); // 일반 적(Boyz) 생성
        State = GameState::InBattle;
        StartBattle();
    }
}

void GameManager::ShowTraderMenu()
{
    int Choice = 0;
    bool ExitMenu = false;

    printf("\n===== 상인 메뉴 =====\n");
    printf("상인을 만났습니다. 메디카에(힐템)를 구매할 수 있습니다.\n");

    while (!ExitMenu)
    {
        printf("1. 메디카에 구매\n");
        printf("2. 내 정보 보기\n");
        printf("3. 다음 스테이지로 이동 (다음 스테이지 : %d)\n", (CurrentStage + 1));
        printf("선택(번호 입력): ");

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
            printf("올바른 번호를 입력하세요.\n");
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
        printf("\n무기를 볼터로 교체했습니다.\n");
		printf("볼터는 원거리 무기로, 3연발 사격이 가능하고, 20~40의 피해를 줍니다.\n");
    }
    else if (player.MyWeapon == WeaponType::ChainSword)
    {
        printf("\n무기를 체인소드로 교체했습니다.\n");
		printf("체인소드는 근접 무기로, 5번에 걸쳐 10~20의 피해를 줍니다.\n");
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
        printf("버그인듯\n");
    }
}

void GameManager::GameVictory()
{
    printf("\n축하합니다! 워뽀쓰를 처치하고 WH40k Malum Caedo를 클리어했습니다!\n");
    printf("For the Emperor!\n");
    printf("게임을 종료합니다.\n");
    exit(0);
}

void GameManager::GameDefeat()
{
    printf("\n플레이어가 사망했습니다...\n");
    printf("WH40k Malum Caedo - 패배\n");
    printf("게임을 종료합니다.\n");
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
    // 이전 적/상인 객체 정리
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

    // 적/상인 배치
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
        printf("\n===== 전투 시작! =====\n");
        printf("\n중간보스 옼스 놉이 등장했습니다!\n");
    }
    else if (StageNum == 12)
    {
        Enemy = new Warboss();
        printf("\n===== 전투 시작! =====\n");
        printf("\n최종보스 옼스 워뽀쓰가 등장했습니다!\n");
    }
    else if (StageNum >= 1)
    {
        Enemy = new Boyz();
        printf("\n===== 전투 시작! =====\n");
        printf("\n적 옼스 보이즈가 등장했습니다!\n");
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
    // 안내 메시지는 ShowTraderMenu()에서만 출력
}

bool GameManager::IsVictoryConditionMet() const
{
    // 최종 스테이지(12)에서 적 처치 시 클리어
    return (CurrentStage == 12 && Enemy != nullptr && !Enemy->IsAlive());
}

void GameManager::GiveLoot()
{
    // 상인 스테이지(3, 6, 9)와 12스테이지에서는 OaksHead를 지급하지 않음
    if (CurrentStage != 12 && CurrentStage != 3 && CurrentStage != 6 && CurrentStage != 9)
    {
        player.OaksHead++;
        printf("전리품: 옼스 머리통 1개를 획득했습니다!\n\n");
    }
}
