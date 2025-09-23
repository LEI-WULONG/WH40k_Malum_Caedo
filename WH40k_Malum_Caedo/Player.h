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
	void TakeDamagePlayer(int InDamage);
	int BoltGunShot(int EnemyHealth);
	int ChainSwordAttack(int EnemyHealth);
	

	

protected:
	std::string Name = "���۳���׾� �غ�";	// ���� ī����
	unsigned int Med = 0;					// �޵�ī�� ���� ����
	unsigned int OaksHead = 0;				// ���� �Ӹ��� ���� ����
	unsigned int HeadPlayer = 45;			// �Ӹ� ü��
	unsigned int ThoraxPlayer = 90;			// ���� ü��
	unsigned int RightArmPlayer = 70;		// ������ ü��
	unsigned int LeftArmPlayer = 70;		// ���� ü��
	unsigned int RightLegPlayer = 70;		// �����ٸ� ü��
	unsigned int LeftLegPlayer = 70;		// �޴ٸ� ü��
	WeaponType MyWeapon;					// ���� �� �����ֳ�
};

