#pragma once
#include "Character.h"

// 옼스 보이즈(일반 적) 클래스 정의
class Boyz : public Character
{
public:
	// 옼스 보이즈가 적을 공격합니다.
	int Attack(Character& Target) override;
	// 옼스 보이즈가 피해를 받습니다.
	void TakeDamage(int Damage, BodyPart Part) override;
	// 옼스 보이즈의 현재 상태(체력 등)를 출력합니다.
	void ViewStatus() const override;
	// 옼스 보이즈가 생존 상태인지 확인합니다.
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

