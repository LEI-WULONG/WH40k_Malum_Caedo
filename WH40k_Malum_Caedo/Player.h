#pragma once
#include <string>
#include "Character.h"

class RougeTrader; // 전방 선언
enum class WeaponType
{
	Bolter = 1,
	ChainSword = 1 << 1
};

class Player :
	public Character
{
public:
	// 파생 함수
	void ViewStatus() const override;
	void TakeDamage(int Damage, BodyPart Part) override;
	int Attack(Character& Target) override;
	bool IsAlive() const override;
	
	// 고유 함수
    void UsingMed();
	void SwapWeapon();
	WeaponType MyWeapon = WeaponType::Bolter;					// 무기 뭐 끼고있냐
	bool BuyMed(RougeTrader& Trader);	

	// 상인 상호작용을 위해 public으로 뺄수밖에 없었음
	unsigned int Med = 0;					// 메디카에 소지 갯수, 2개가 최대
	unsigned int OaksHead = 0;				// 옼스 머리통 소지 갯수

protected:
	std::string Name = "나쁜놈다죽어 해병";	// 말룸 카에도
	unsigned int Head = 45;					// 머리 체력
	unsigned int Thorax = 90;				// 몸통 체력
	unsigned int RightArm = 70;				// 오른팔 체력
	unsigned int LeftArm = 70;				// 왼팔 체력
	unsigned int RightLeg = 70;				// 오른다리 체력
	unsigned int LeftLeg = 70;				// 왼다리 체력
};

