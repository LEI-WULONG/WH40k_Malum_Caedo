#pragma once
#include "Character.h"

// 옼스 워뽀쓰(최종 보스) 클래스 정의
class Warboss : public Character
{
public:
	// 옼스 워뽀쓰가 적을 공격합니다.
	int Attack(Character& Target) override;
	// 옼스 워뽀쓰가 피해를 받습니다.
	void TakeDamage(int Damage, BodyPart Part) override;
	// 옼스 워뽀쓰가 현재 상태(체력 등)를 출력합니다.
	void ViewStatus() const override;
	// 옼스 워뽀쓰가 생존 상태인지 확인합니다.
	bool IsAlive() const override;

protected:
	std::string Name = "옼스 워뽀쓰";
	unsigned int Head = 55;
	unsigned int Thorax = 105;
	unsigned int RightArm = 85;
	unsigned int LeftArm = 85;
	unsigned int RightLeg = 85;
	unsigned int LeftLeg = 85;
};

