#pragma once
#include <string>
#include "Character.h"

class RougeTrader; // ���� ����
enum class WeaponType
{
	Bolter = 1,
	ChainSword = 1 << 1
};

class Player :
	public Character
{
public:
	// �Ļ� �Լ�
	void ViewStatus() const override;
	void TakeDamage(int Damage, BodyPart Part) override;
	int Attack(Character& Target) override;
	bool IsAlive() const override;
	
	// ���� �Լ�
    void UsingMed();
	void SwapWeapon();
	WeaponType MyWeapon = WeaponType::Bolter;					// ���� �� �����ֳ�
	bool BuyMed(RougeTrader& Trader);	

	// ���� ��ȣ�ۿ��� ���� public���� �����ۿ� ������
	unsigned int Med = 0;					// �޵�ī�� ���� ����, 2���� �ִ�
	unsigned int OaksHead = 0;				// ���� �Ӹ��� ���� ����

protected:
	std::string Name = "���۳���׾� �غ�";	// ���� ī����
	unsigned int Head = 45;					// �Ӹ� ü��
	unsigned int Thorax = 90;				// ���� ü��
	unsigned int RightArm = 70;				// ������ ü��
	unsigned int LeftArm = 70;				// ���� ü��
	unsigned int RightLeg = 70;				// �����ٸ� ü��
	unsigned int LeftLeg = 70;				// �޴ٸ� ü��
};

