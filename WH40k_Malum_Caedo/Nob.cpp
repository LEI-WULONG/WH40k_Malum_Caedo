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

		printf("%s�� %s ������ %d�� ���ظ� ����! (���� ü��: %u)\n",
			Name.c_str(), Character::BodyPartToString(Part), Damage, *PartHP);
	}
}

void Nob::ViewStatus() const
{
	printf("------ ���� ü�� ------\n");
	printf("�� �̸�: %s\n", Name.c_str());
	printf("�Ӹ�: %d\n", Head);
	printf("����: %d\n", Thorax);
	printf("������: %d / ", RightArm);
	printf("����: %d\n", LeftArm);
	printf("�����ٸ�: %d / ", RightLeg);
	printf("�޴ٸ�: %d\n\n", LeftLeg);
}

bool Nob::IsAlive() const
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