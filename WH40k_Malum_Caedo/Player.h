#pragma once
#include <string>

enum class WeaponType
{
	Bolter = 1,
	ChainSword = 1 << 1
};

enum class BodyPartsPlayer
{
	eHeadPlayer = 0,
	eThoraxPlayer,
	eRightArmPlayer,
	eLeftArmPlayer,
	eRightLegPlayer,
	eLeftLegPlayer
};

class Player
{
public:
    void UsingMed();
	void ViewStatus();
	void SwapWeapon();
	bool IsAlive();
	void TakeDamage(int InDamage);
	int BoltGunShot(int EnemyHealth);
	int ChainSwordAttack(int EnemyHealth);
	void ArmBrokenDebuff(); // 팔, 다리 나갔을때 처리를 어케하지 <- 해결안됨
	void LegBrokenDebuff();
	void BleedingDebuff();
	

	

protected:
	std::string Name = "나쁜놈다죽어 해병";	// 말룸 카에도
	unsigned int Med = 0;					// 메디카에 소지 갯수
	unsigned int OaksHead = 0;				// 옼스 머리통 소지 갯수
	unsigned int HeadPlayer = 45;			// 머리 체력
	unsigned int ThoraxPlayer = 90;			// 몸통 체력
	unsigned int RightArmPlayer = 70;		// 오른팔 체력
	unsigned int LeftArmPlayer = 70;		// 왼팔 체력
	unsigned int RightLegPlayer = 70;		// 오른다리 체력
	unsigned int LeftLegPlayer = 70;		// 왼다리 체력
	bool IsBleeding = 0;					// 출혈상태냐 아니냐
	WeaponType MyWeapon;
};

