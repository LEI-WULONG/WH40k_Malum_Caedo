#pragma once
#include "Character.h"

class Boyz :
    public Character
{
public:
	int Attack(Character& Target) override;
	void TakeDamage(int Damage, BodyPart Part) override;
	void ViewStatus() const override;
	bool IsAlive() const override;

protected:
	std::string Name = "옼스 보이즈";
	unsigned int Head = 35;
	unsigned int Thorax = 80;
	unsigned int RightArm = 60;
	unsigned int LeftArm = 60;
	unsigned int RightLeg = 60;
	unsigned int LeftLeg = 60;
};

