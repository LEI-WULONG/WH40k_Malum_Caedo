#include "Warboss.h"
#define RED   "\x1b[31m"
#define RESET "\x1b[0m"

// 옼스 워뽀쓰가 적을 공격합니다.
int Warboss::Attack(Character& Target)
{
	int Damage = rand() % 10 + 35;
	Target.TakeDamage(Damage, BodyPart::Head);
	return Damage;
}

// 옼스 워뽀쓰가 피해를 받습니다.
void Warboss::TakeDamage(int Damage, BodyPart Part)
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

// 옼스 워뽀쓰가 현재 상태(체력 등)를 출력합니다.
void Warboss::ViewStatus() const
{
    printf(RED "------ 적의 체력 ------\n");
    printf("적 이름: %s\n", Name.c_str());
    printf("머리: %d\n", Head);
    printf("몸통: %d\n", Thorax);
    printf("오른팔: %d / ", RightArm);
    printf("왼팔: %d\n", LeftArm);
    printf("오른다리: %d / ", RightLeg);
    printf("왼다리: %d\n\n" RESET, LeftLeg);
}

// 옼스 워뽀쓰가 생존 상태인지 확인합니다.
bool Warboss::IsAlive() const
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