#include "Nob.h"

int Nob::Attack(Character& Target)
{
	int Damage = rand() % 11 + 25;
	Target.TakeDamage(Damage, BodyPart::Head);
	return Damage;
}

void Nob::TakeDamage(int Damage, BodyPart Part)
{
	unsigned int* PartHP = nullptr;

	if (Part == BodyPart::Head) {
		PartHP = &Head;
	}
	else if (Part == BodyPart::Thorax) {
		PartHP = &Thorax;
	}
	else if (Part == BodyPart::RightArm) {
		PartHP = &RightArm;
	}
	else if (Part == BodyPart::LeftArm) {
		PartHP = &LeftArm;
	}
	else if (Part == BodyPart::RightLeg) {
		PartHP = &RightLeg;
	}
	else if (Part == BodyPart::LeftLeg) {
		PartHP = &LeftLeg;
	}

	if (PartHP) 
	{
		if (*PartHP > static_cast<unsigned int>(Damage))
		{
			*PartHP -= Damage;
		}
		else
		{
			*PartHP = 0;
		}

		printf("%s가 %s 부위에 %d의 피해를 입음! (남은 체력: %u)\n",
			Name.c_str(), Character::BodyPartToString(Part), Damage, *PartHP);
	}
}
