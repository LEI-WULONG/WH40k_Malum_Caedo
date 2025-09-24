#pragma once
#include "Character.h"
class Warboss :
    public Character
{
public:
	int Attack(Character& Target) override;
	void TakeDamage(int Damage, BodyPart Part) override;

protected:
	std::string Name = "ž±½º ¿ö»Ç¾²";
	unsigned int Head = 55;
	unsigned int Thorax = 105;
	unsigned int RightArm = 85;
	unsigned int LeftArm = 85;
	unsigned int RightLeg = 85;
	unsigned int LeftLeg = 85;
};

