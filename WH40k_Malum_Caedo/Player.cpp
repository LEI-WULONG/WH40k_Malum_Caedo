#include "Player.h"
#include "RougeTrader.h"

void Player::UsingMed()
{
	const int MaxMed = 2;
	const int MaxHead = 45;
	const int MaxThorax = 90;
	const int MaxArm = 70;
	const int MaxLeg = 70;

	if (Med == 0)
	{
		printf("소지하고 있는 메디카에가 없습니다.\n");
	}
	else
	{
		Med--;
		printf("메디카에를 사용했습니다. 보유 메디카에 : %d / %d\n", Med, MaxMed);
		Head = MaxHead;
		Thorax = MaxThorax;
		RightArm = MaxArm;
		LeftArm = MaxArm;
		RightLeg = MaxLeg;
		LeftLeg = MaxLeg;
	}
}

void Player::ViewStatus() const
{
	int PlayerTotalHealth = Head + Thorax + RightArm + LeftArm + RightLeg + LeftLeg;
	const int PlayerWoundAlmostDeath = 180;
	const int PlayerWound = 360;
	const int PlayerWoundHealty = 415;

	// 무기 이름 문자열 결정
	const char* weaponName = (MyWeapon == WeaponType::Bolter) ? "볼터" : "체인소드";

	// 건강 상태 판정
	const char* HealthState = nullptr;
	if (PlayerTotalHealth <= PlayerWoundAlmostDeath)
	{
		HealthState = "심각함";
	}
	else if (PlayerTotalHealth <= PlayerWound)
	{
		HealthState = "부상";
	}
	else if (PlayerTotalHealth <= PlayerWoundHealty)
	{
		HealthState = "양호";
	}
	else
	{
		HealthState = "최상";
	}

	printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : %s\n----- 체력 -----\n",
		Name.c_str(), OaksHead, weaponName);
	printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : %d\n",
		Head, Thorax, RightArm, LeftArm, RightLeg, LeftLeg);
	printf("최종 건강 상태 : %s\n\n", HealthState);
}

void Player::SwapWeapon()
{
	if (MyWeapon == WeaponType::Bolter)
	{
		MyWeapon = WeaponType::ChainSword;
	}
	else if (MyWeapon == WeaponType::ChainSword)
	{
		MyWeapon = WeaponType::Bolter;
	}
}

bool Player::BuyMed(RougeTrader& Trader)
{
	return Trader.SellMed(*this);
}

bool Player::IsAlive() const
{
	// 머리, 몸통, 두 팔, 두 다리 중 하나라도 사망 조건이면 false
	if (Head < 0) 
	{
		return false;
	}
	if (Thorax < 0) 
	{
		return false;
	}
	if (RightArm < 0 && LeftArm < 0) 
	{
		return false;
	}
	if (RightLeg < 0 && LeftLeg < 0) 
	{
		return false;
	}
	return true;
}

void Player::TakeDamage(int Damage, BodyPart Part)
{
	const int DodgeChance = 1;
	int DodgeRoll = rand() % 5 + 1;
	int AttackRollBodyPart = rand() % 6;

	if (DodgeChance == DodgeRoll)
	{
		printf("\n공격을 피했습니다!\n\n");
		return;
	}

	if (AttackRollBodyPart == static_cast<int>(BodyPart::Head))
	{
		Head -= Damage;
		if (Head < 0) 
		{ 
			Head = 0; 
		}
		printf("\n적에게 머리를 맞았습니다!\n머리 체력 : %d / 45\n\n", Head);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::Thorax))
	{
		Thorax -= Damage;
		if (Thorax < 0) 
		{ 
			Thorax = 0; 
		}
		printf("\n적에게 몸통을 맞았습니다!\n몸통 체력 : %d / 90\n\n", Thorax);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::RightArm))
	{
		RightArm -= Damage;
		if (RightArm < 0) 
		{ 
			RightArm = 0; 
		}
		printf("\n적에게 오른팔을 맞았습니다!\n오른팔 체력 : %d / 70\n\n", RightArm);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::LeftArm))
	{
		LeftArm -= Damage;
		if (LeftArm < 0) 
		{ 
			LeftArm = 0; 
		}
		printf("\n적에게 왼팔을 맞았습니다!\n왼팔 체력 : %d / 70\n\n", LeftArm);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::RightLeg))
	{
		RightLeg -= Damage;
		if (RightLeg < 0) 
		{ 
			RightLeg = 0; 
		}
		printf("\n적에게 오른다리를 맞았습니다!\n오른다리 체력 : %d / 70\n\n", RightLeg);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::LeftLeg))
	{
		LeftLeg -= Damage;
		if (LeftLeg < 0) 
		{ 
			LeftLeg = 0; 
		}
		printf("\n적에게 왼다리를 맞았습니다!\n왼다리 체력 : %d / 70\n\n", LeftLeg);
	}
	else
	{
		printf("버그인듯\n");
	}

	if (!IsAlive()) 
	{
		printf("\n플레이어가 사망했습니다!\n");
	}
}

int Player::Attack(Character& Target)
{
	int TotalDamage = 0;
	if (MyWeapon == WeaponType::Bolter)
	{
		for (int i = 0; i < 3; i++)
		{
			int Damage = rand() % 21 + 20;
			printf("\n탕! %d의 데미지\n", Damage);
			int Part = rand() % static_cast<int>(BodyPart::NumParts);
			Target.TakeDamage(Damage, static_cast<Character::BodyPart>(Part));
			TotalDamage += Damage;
			
		}
	}
	else if (MyWeapon == WeaponType::ChainSword)
	{
		int Part = rand() % static_cast<int>(BodyPart::NumParts);
		for (int i = 0; i < 5; i++)
		{
			int Damage = rand() % 11 + 10;
			printf("\n가가가각! %d의 데미지\n", Damage);
			Target.TakeDamage(Damage, static_cast<Character::BodyPart>(Part));
			TotalDamage += Damage;
			
		}
	}
	else
	{
		printf("버그인듯!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}

	return TotalDamage;
}


