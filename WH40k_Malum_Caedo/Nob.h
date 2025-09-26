#pragma once
#include "Character.h"

// ��(�߰�����) Ŭ���� ����
class Nob : public Character
{
public:
	// ���� ���� �����մϴ�.
	int Attack(Character& Target) override;
	// ���� ���ظ� �޽��ϴ�.
	void TakeDamage(int Damage, BodyPart Part) override;
	// ���� ���� ����(ü�� ��)�� ����մϴ�.
	void ViewStatus() const override;
	// ���� ���� �������� Ȯ���մϴ�.
	bool IsAlive() const override;

protected:
	std::string Name = "���� ��";
	unsigned int Head = 45;
	unsigned int Thorax = 95;
	unsigned int RightArm = 75;
	unsigned int LeftArm = 75;
	unsigned int RightLeg = 75;
	unsigned int LeftLeg = 75;
};
