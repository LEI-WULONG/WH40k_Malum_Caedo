#pragma once
#include "Character.h"

// ���� ������(�Ϲ� ��) Ŭ���� ����
class Boyz : public Character
{
public:
	// ���� ����� ���� �����մϴ�.
	int Attack(Character& Target) override;
	// ���� ����� ���ظ� �޽��ϴ�.
	void TakeDamage(int Damage, BodyPart Part) override;
	// ���� �������� ���� ����(ü�� ��)�� ����մϴ�.
	void ViewStatus() const override;
	// ���� ����� ���� �������� Ȯ���մϴ�.
	bool IsAlive() const override;

protected:
	std::string Name = "���� ������";
	unsigned int Head = 35;
	unsigned int Thorax = 80;
	unsigned int RightArm = 60;
	unsigned int LeftArm = 60;
	unsigned int RightLeg = 60;
	unsigned int LeftLeg = 60;
};

