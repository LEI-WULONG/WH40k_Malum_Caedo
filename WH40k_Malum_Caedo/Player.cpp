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
		printf("�����ϰ� �ִ� �޵�ī���� �����ϴ�.\n");
	}
	else
	{
		Med--;
		printf("�޵�ī���� ����߽��ϴ�. ���� �޵�ī�� : %d / %d\n", Med, MaxMed);
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

	// ���� �̸� ���ڿ� ����
	const char* weaponName = (MyWeapon == WeaponType::Bolter) ? "����" : "ü�μҵ�";

	// �ǰ� ���� ����
	const char* HealthState = nullptr;
	if (PlayerTotalHealth <= PlayerWoundAlmostDeath)
	{
		HealthState = "�ɰ���";
	}
	else if (PlayerTotalHealth <= PlayerWound)
	{
		HealthState = "�λ�";
	}
	else if (PlayerTotalHealth <= PlayerWoundHealty)
	{
		HealthState = "��ȣ";
	}
	else
	{
		HealthState = "�ֻ�";
	}

	printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : %s\n----- ü�� -----\n",
		Name.c_str(), OaksHead, weaponName);
	printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : %d\n",
		Head, Thorax, RightArm, LeftArm, RightLeg, LeftLeg);
	printf("���� �ǰ� ���� : %s\n\n", HealthState);
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
	// �Ӹ�, ����, �� ��, �� �ٸ� �� �ϳ��� ��� �����̸� false
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
		printf("\n������ ���߽��ϴ�!\n\n");
		return;
	}

	if (AttackRollBodyPart == static_cast<int>(BodyPart::Head))
	{
		Head -= Damage;
		if (Head < 0) 
		{ 
			Head = 0; 
		}
		printf("\n������ �Ӹ��� �¾ҽ��ϴ�!\n�Ӹ� ü�� : %d / 45\n\n", Head);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::Thorax))
	{
		Thorax -= Damage;
		if (Thorax < 0) 
		{ 
			Thorax = 0; 
		}
		printf("\n������ ������ �¾ҽ��ϴ�!\n���� ü�� : %d / 90\n\n", Thorax);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::RightArm))
	{
		RightArm -= Damage;
		if (RightArm < 0) 
		{ 
			RightArm = 0; 
		}
		printf("\n������ �������� �¾ҽ��ϴ�!\n������ ü�� : %d / 70\n\n", RightArm);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::LeftArm))
	{
		LeftArm -= Damage;
		if (LeftArm < 0) 
		{ 
			LeftArm = 0; 
		}
		printf("\n������ ������ �¾ҽ��ϴ�!\n���� ü�� : %d / 70\n\n", LeftArm);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::RightLeg))
	{
		RightLeg -= Damage;
		if (RightLeg < 0) 
		{ 
			RightLeg = 0; 
		}
		printf("\n������ �����ٸ��� �¾ҽ��ϴ�!\n�����ٸ� ü�� : %d / 70\n\n", RightLeg);
	}
	else if (AttackRollBodyPart == static_cast<int>(BodyPart::LeftLeg))
	{
		LeftLeg -= Damage;
		if (LeftLeg < 0) 
		{ 
			LeftLeg = 0; 
		}
		printf("\n������ �޴ٸ��� �¾ҽ��ϴ�!\n�޴ٸ� ü�� : %d / 70\n\n", LeftLeg);
	}
	else
	{
		printf("�����ε�\n");
	}

	if (!IsAlive()) 
	{
		printf("\n�÷��̾ ����߽��ϴ�!\n");
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
			printf("\n��! %d�� ������\n", Damage);
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
			printf("\n��������! %d�� ������\n", Damage);
			Target.TakeDamage(Damage, static_cast<Character::BodyPart>(Part));
			TotalDamage += Damage;
			
		}
	}
	else
	{
		printf("�����ε�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}

	return TotalDamage;
}


