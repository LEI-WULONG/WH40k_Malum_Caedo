#pragma once
#include <string>
#include "Character.h"

class RougeTrader; // 전방 선언
enum class WeaponType
{
	Bolter = 1,
	ChainSword
};

class Player :
	public Character
{
public:
	// 파생 함수
	void ViewStatus() const override; // 플레이어의 상태를 출력합니다.
	void TakeDamage(int Damage, BodyPart Part) override; // 플레이어가 피해를 받습니다.
	int Attack(Character& Target) override; // 플레이어가 적을 공격합니다.
	bool IsAlive() const override; // 플레이어가 생존 상태인지 확인합니다.
	
	// 고유 함수
    void UsingMed(); // 플레이어가 메디카에를 사용합니다.
	void SwapWeapon(); // 플레이어의 무기를 교체합니다.
	WeaponType MyWeapon = WeaponType::Bolter;					// 무기 뭐 끼고있냐
	bool BuyMed(RougeTrader& Trader); // 상인에게 메디카에를 구매합니다.

	// 상인 상호작용을 위해 public으로 뺄수밖에 없었음
	unsigned int Med = 0;					// 메디카에 소지 갯수, 2개가 최대
	unsigned int OaksHead = 0;				// 옼스 머리통 소지 갯수

protected:
	std::string Name = "나쁜놈다죽어 해병";	// 말룸 카에도
	int Head = 45;					// 머리 체력
	int Thorax = 90;				// 몸통 체력
	int RightArm = 70;				// 오른팔 체력
	int LeftArm = 70;				// 왼팔 체력
	int RightLeg = 70;				// 오른다리 체력
	int LeftLeg = 70;				// 왼다리 체력
};

