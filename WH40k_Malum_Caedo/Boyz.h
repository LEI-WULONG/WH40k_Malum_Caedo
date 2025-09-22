#pragma once
#include "Entity.h"
class Boyz :
    public Entity
{

protected:
	std::string Name = "옼스 보이즈";
	const int AttackPower = 0;
	unsigned int HeadHealth = 35;
	unsigned int ThoraxHealth = 80;
	unsigned int RightArmHealth = 60;
	unsigned int LeftArmHealth = 60;
	unsigned int RightLegHealth = 60;
	unsigned int LeftLegHealth = 60;
};

