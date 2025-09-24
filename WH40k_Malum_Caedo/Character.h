#pragma once
#include <string>

class Character
{
public:
	enum class BodyPart 
	{
		Head,
		Thorax,
		RightArm,
		LeftArm,
		RightLeg,
		LeftLeg,
		NumParts
	};

	static const char* BodyPartToString(BodyPart Part)
	{
		switch (Part)
		{
		case BodyPart::Head:
			return "�Ӹ�";
		case BodyPart::Thorax:
			return "����";
		case BodyPart::RightArm:
			return "������";
		case BodyPart::LeftArm:
			return "����";
		case BodyPart::RightLeg:
			return "�����ٸ�";
		case BodyPart::LeftLeg:
			return "�޴ٸ�";
		default:
			return "�� �� ����";
		}
	}

	virtual void ViewStatus() const = 0;
	virtual bool IsAlive() const = 0;
	virtual void TakeDamage(int Damage, BodyPart Part) = 0; // �Ļ� Ŭ�������� ���� ���� ó��
	virtual int Attack(Character& Target) = 0;

	virtual ~Character() {}


protected:
	std::string Name;
	unsigned int Head = 0;
	unsigned int Thorax = 0;
	unsigned int RightArm = 0;
	unsigned int LeftArm = 0;
	unsigned int RightLeg = 0;
	unsigned int LeftLeg = 0;
};

