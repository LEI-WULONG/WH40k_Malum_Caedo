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
			return "머리";
		case BodyPart::Thorax:
			return "몸통";
		case BodyPart::RightArm:
			return "오른팔";
		case BodyPart::LeftArm:
			return "왼팔";
		case BodyPart::RightLeg:
			return "오른다리";
		case BodyPart::LeftLeg:
			return "왼다리";
		default:
			return "알 수 없음";
		}
	}

	virtual void ViewStatus() const = 0;
	virtual bool IsAlive() const = 0;
	virtual void TakeDamage(int Damage, BodyPart Part) = 0; // 파생 클래스에서 부위 랜덤 처리
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

