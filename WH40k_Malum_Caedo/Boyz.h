#pragma once
#include "Enemy.h"
#include "Player.h"

class Boyz :
    public Enemy
{
public:
	virtual void Attack(Player& player) override;

protected:
	std::string Name = "���� ������";
	int AttackPowerEnemy = 0; // �Լ� �ȿ��� ����
	unsigned int HeadHealth = 35;
	unsigned int ThoraxHealth = 80;
	unsigned int RightArmHealth = 60;
	unsigned int LeftArmHealth = 60;
	unsigned int RightLegHealth = 60;
	unsigned int LeftLegHealth = 60;
};

