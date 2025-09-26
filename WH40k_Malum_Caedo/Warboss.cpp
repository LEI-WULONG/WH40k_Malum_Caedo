#include "Warboss.h"
#define RED   "\x1b[31m"
#define RESET "\x1b[0m"

// ���� ���Ǿ��� ���� �����մϴ�.
int Warboss::Attack(Character& Target)
{
	int Damage = rand() % 10 + 35;
	Target.TakeDamage(Damage, BodyPart::Head);
	return Damage;
}

// ���� ���Ǿ��� ���ظ� �޽��ϴ�.
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

        printf("%s�� %s ������ %d�� ���ظ� ����! (���� ü��: %u)\n",
            Name.c_str(), Character::BodyPartToString(Part), Damage, *PartHP);
    }
}

// ���� ���Ǿ��� ���� ����(ü�� ��)�� ����մϴ�.
void Warboss::ViewStatus() const
{
    printf(RED "------ ���� ü�� ------\n");
    printf("�� �̸�: %s\n", Name.c_str());
    printf("�Ӹ�: %d\n", Head);
    printf("����: %d\n", Thorax);
    printf("������: %d / ", RightArm);
    printf("����: %d\n", LeftArm);
    printf("�����ٸ�: %d / ", RightLeg);
    printf("�޴ٸ�: %d\n\n" RESET, LeftLeg);
}

// ���� ���Ǿ��� ���� �������� Ȯ���մϴ�.
bool Warboss::IsAlive() const
{
    // �Ӹ�, ����, �� ��, �� �ٸ� �� �ϳ��� ��� �����̸� false
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