#pragma once
#include "Enemy.h"
#include "Player.h"

class Boyz :
    public Enemy
{
public:
	virtual void Attack(Player& player) override;

protected:
	std::string Name = "옼스 보이즈";
	int AttackPowerEnemy = 0; // 함수 안에서 랜덤
	unsigned int HeadHealth = 35;
	unsigned int ThoraxHealth = 80;
	unsigned int RightArmHealth = 60;
	unsigned int LeftArmHealth = 60;
	unsigned int RightLegHealth = 60;
	unsigned int LeftLegHealth = 60;
};

