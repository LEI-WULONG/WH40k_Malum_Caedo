#pragma once
#include "Character.h"

// 놉(중간보스) 클래스 정의
class Nob : public Character
{
public:
	// 놉이 적을 공격합니다.
	int Attack(Character& Target) override;
	// 놉이 피해를 받습니다.
	void TakeDamage(int Damage, BodyPart Part) override;
	// 놉의 현재 상태(체력 등)를 출력합니다.
	void ViewStatus() const override;
	// 놉이 생존 상태인지 확인합니다.
	bool IsAlive() const override;

protected:
	std::string Name = "옼스 놉";
	unsigned int Head = 45;
	unsigned int Thorax = 95;
	unsigned int RightArm = 75;
	unsigned int LeftArm = 75;
	unsigned int RightLeg = 75;
	unsigned int LeftLeg = 75;
};
