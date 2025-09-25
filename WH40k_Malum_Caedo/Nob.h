#pragma once
#include "Character.h"

class Nob :
    public Character
{
public:
	int Attack(Character& Target) override;
	void TakeDamage(int Damage, BodyPart Part) override;
	void ViewStatus() const override;
	bool IsAlive() const override;

protected:
	std::string Name = "ž±½º ³ñ";
	unsigned int Head = 45;
	unsigned int Thorax = 95;
	unsigned int RightArm = 75;
	unsigned int LeftArm = 75;
	unsigned int RightLeg = 75;
	unsigned int LeftLeg = 75;
};
