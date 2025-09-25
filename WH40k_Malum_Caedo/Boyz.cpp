#include "Boyz.h"

int Boyz::Attack(Character& Target)
{
	int Damage = rand() % 11 + 20;
	Target.TakeDamage(Damage, BodyPart::Head);
	return Damage;
}

void Boyz::TakeDamage(int Damage, BodyPart Part)
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

        printf("\n%s가 %s 부위에 %d의 피해를 입음! (남은 체력: %u)\n",
            Name.c_str(), Character::BodyPartToString(Part), Damage, *PartHP);
    }
}

void Boyz::ViewStatus() const
{
    printf("적 이름: %s\n", Name.c_str());
    printf("머리: %d\n", Head);
    printf("몸통: %d\n", Thorax);
    printf("오른팔: %d\n", RightArm);
    printf("왼팔: %d\n", LeftArm);
    printf("오른다리: %d\n", RightLeg);
    printf("왼다리: %d\n\n", LeftLeg);
}

bool Boyz::IsAlive() const
{
    // 머리, 몸통, 두 팔, 두 다리 중 하나라도 사망 조건이면 false
    if (Head <= 0)
    {
        return false;
    }
    if (Thorax <= 0)
    {
        return false;
    }
    if ((RightArm <= 0) && (LeftArm <= 0))
    {
        return false;
    }
    if ((RightLeg <= 0) && (LeftLeg <= 0))
    {
        return false;
    }
    
    return true;
}


