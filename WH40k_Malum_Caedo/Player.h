#pragma once
#include <string>
#include "Character.h"

class RougeTrader; // ���� ����
enum class WeaponType
{
	Bolter = 1,
	ChainSword
};

class Player :
	public Character
{
public:
	// �Ļ� �Լ�
	void ViewStatus() const override; // �÷��̾��� ���¸� ����մϴ�.
	void TakeDamage(int Damage, BodyPart Part) override; // �÷��̾ ���ظ� �޽��ϴ�.
	int Attack(Character& Target) override; // �÷��̾ ���� �����մϴ�.
	bool IsAlive() const override; // �÷��̾ ���� �������� Ȯ���մϴ�.
	
	// ���� �Լ�
    void UsingMed(); // �÷��̾ �޵�ī���� ����մϴ�.
	void SwapWeapon(); // �÷��̾��� ���⸦ ��ü�մϴ�.
	WeaponType MyWeapon = WeaponType::Bolter;					// ���� �� �����ֳ�
	bool BuyMed(RougeTrader& Trader); // ���ο��� �޵�ī���� �����մϴ�.

	// ���� ��ȣ�ۿ��� ���� public���� �����ۿ� ������
	unsigned int Med = 0;					// �޵�ī�� ���� ����, 2���� �ִ�
	unsigned int OaksHead = 0;				// ���� �Ӹ��� ���� ����

protected:
	std::string Name = "���۳���׾� �غ�";	// ���� ī����
	int Head = 45;					// �Ӹ� ü��
	int Thorax = 90;				// ���� ü��
	int RightArm = 70;				// ������ ü��
	int LeftArm = 70;				// ���� ü��
	int RightLeg = 70;				// �����ٸ� ü��
	int LeftLeg = 70;				// �޴ٸ� ü��
};

