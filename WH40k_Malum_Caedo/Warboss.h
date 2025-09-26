#pragma once
#include "Character.h"

// ���� ���Ǿ�(���� ����) Ŭ���� ����
class Warboss : public Character
{
public:
	// ���� ���Ǿ��� ���� �����մϴ�.
	int Attack(Character& Target) override;
	// ���� ���Ǿ��� ���ظ� �޽��ϴ�.
	void TakeDamage(int Damage, BodyPart Part) override;
	// ���� ���Ǿ��� ���� ����(ü�� ��)�� ����մϴ�.
	void ViewStatus() const override;
	// ���� ���Ǿ��� ���� �������� Ȯ���մϴ�.
	bool IsAlive() const override;

protected:
	std::string Name = "���� ���Ǿ�";
	unsigned int Head = 55;
	unsigned int Thorax = 105;
	unsigned int RightArm = 85;
	unsigned int LeftArm = 85;
	unsigned int RightLeg = 85;
	unsigned int LeftLeg = 85;
};

