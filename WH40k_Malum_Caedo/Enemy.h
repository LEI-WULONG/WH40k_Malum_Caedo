#pragma once
#include <string>

class Enemy
{
public:
	virtual void Attack(Player& player);


protected:
	std::string Name;
	const int AttackPowerEnemy = 0;
	unsigned int HeadHealth = 0;
	unsigned int ThoraxHealth = 0;
	unsigned int RightArmHealth = 0;
	unsigned int LeftArmHealth = 0;
	unsigned int RightLegHealth = 0;
	unsigned int LeftLegHealth = 0;
};

