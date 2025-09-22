#pragma once
#include <string>

class Entity
{
public:
	virtual void Attack() = 0;
	virtual void DodgeChance() = 0;


protected:
	std::string Name;
	const int AttackPower = 0;
	unsigned int HeadHealth = 0;
	unsigned int ThoraxHealth = 0;
	unsigned int RightArmHealth = 0;
	unsigned int LeftArmHealth = 0;
	unsigned int RightLegHealth = 0;
	unsigned int LeftLegHealth = 0;
};

