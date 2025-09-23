#include "Player.h"

void Player::UsingMed()
{
    if (Med == 0)
    {
        printf("�����ϰ� �ִ� �޵�ī���� �����ϴ�.\n");
    }
    else
    {
        Med--;
        printf("�޵�ī���� ����߽��ϴ�. ���� �޵�ī�� : %d / 2", Med);
        HeadPlayer = 45;
        ThoraxPlayer = 90;
        RightArmPlayer = 70;
        LeftArmPlayer = 70;
        RightLegPlayer = 70;
        LeftLegPlayer = 70;
    }
}

void Player::ViewStatus()
{
    int PlayerTotalHealth = HeadPlayer + ThoraxPlayer + RightArmPlayer + LeftArmPlayer
        + RightLegPlayer + LeftLegPlayer;
    const int PlayerWoundAlmostDeath = 180;
    const int PlayerWound = 360;
    const int PlayerWoundHealty = 415;

    if ((PlayerTotalHealth <= PlayerWoundAlmostDeath) && (MyWeapon == WeaponType::Bolter))
    {
        printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : ����\n----- ü�� -----\n", Name.c_str(), OaksHead);
        printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("���� �ǰ� ���� : �ɰ���");
    }
    else if ((PlayerTotalHealth <= PlayerWound) && (MyWeapon == WeaponType::Bolter))
    {
        printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : ����\n----- ü�� -----\n", Name.c_str(), OaksHead);
        printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("���� �ǰ� ���� : �λ�");
    }
    else if ((PlayerTotalHealth <= PlayerWoundHealty) && (MyWeapon == WeaponType::Bolter))
    {
        printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : ����\n----- ü�� -----\n", Name.c_str(), OaksHead);
        printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("���� �ǰ� ���� : ��ȣ");
    }

    if ((PlayerTotalHealth <= PlayerWoundAlmostDeath) && (MyWeapon == WeaponType::ChainSword))
    {
        printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : ü�μҵ�\n----- ü�� -----\n", Name.c_str(), OaksHead);
        printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("���� �ǰ� ���� : �ɰ���");
    }
    else if ((PlayerTotalHealth <= PlayerWound) && (MyWeapon == WeaponType::ChainSword))
    {
        printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : ü�μҵ�\n----- ü�� -----\n", Name.c_str(), OaksHead);
        printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("���� �ǰ� ���� : �λ�");
    }
    else if ((PlayerTotalHealth <= PlayerWoundHealty) && (MyWeapon == WeaponType::ChainSword))
    {
        printf("�̸� : %s\n������ : �Ӹ��� %d��\n���� ���� : ü�μҵ�\n----- ü�� -----\n", Name.c_str(), OaksHead);
        printf("�Ӹ� : %d\n���� : %d\n������ : %d\n���� : %d\n�����ٸ� : %d\n�޴ٸ� : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("���� �ǰ� ���� : ��ȣ");
    }
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

bool Player::IsAlive()
{
    int TotalArmHealth = (RightArmPlayer + LeftArmPlayer);
    int TotalLegHealth = (RightLegPlayer + LeftLegPlayer);
    if ((HeadPlayer > 0) && (ThoraxPlayer > 0) && (TotalArmHealth > 0) && (TotalLegHealth > 0))
    {
        return true;
    }
    else if ((TotalArmHealth == 0) || (TotalLegHealth == 0))
    {
        return false;
    }
    else if (HeadPlayer == 0)
    {
        return false;
    }
    else if (ThoraxPlayer == 0)
    {
        return false;
    }
    else
    {
        printf("�����ε�");
    }
}

void Player::TakeDamagePlayer(int InDamage)
{
    const int DodgeChance = 1;
    const int BleedingDodgeChance = 1;
    int DodgeRoll = rand() % 5 + 1;
    
    int AttackRollBodyPart = rand() % 6;
    int BleedingRoll = rand() % 8;

    if (DodgeChance == DodgeRoll)
    {
        printf("������ ���߽��ϴ�!\n");
    }

    if (static_cast<int>(BodyPartsPlayer::eHeadPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            HeadPlayer -= InDamage;
            printf("������ �Ӹ��� �°�, ������ �Ͼ���ϴ�!\n�Ӹ� ü�� : %d / 45", HeadPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            HeadPlayer -= InDamage;
            printf("������ �Ӹ��� �¾ҽ��ϴ�!\n�Ӹ� ü�� : %d / 45", HeadPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eThoraxPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            ThoraxPlayer -= InDamage;
            printf("������ ������ �°�, ������ �Ͼ���ϴ�!\n���� ü�� : %d / 90", ThoraxPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            ThoraxPlayer -= InDamage;
            printf("������ ������ �¾ҽ��ϴ�!\n���� ü�� : %d / 90", ThoraxPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eRightArmPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            RightArmPlayer -= InDamage;
            printf("������ �������� �°�, ������ �Ͼ���ϴ�!\n������ ü�� : %d / 70", RightArmPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            RightArmPlayer -= InDamage;
            printf("������ �������� �¾ҽ��ϴ�!\n������ ü�� : %d / 70", RightArmPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eLeftArmPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            LeftArmPlayer -= InDamage;
            printf("������ ������ �°�, ������ �Ͼ���ϴ�!\n������ ü�� : %d / 70", LeftArmPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            LeftArmPlayer -= InDamage;
            printf("������ ������ �¾ҽ��ϴ�!\n���� ü�� : %d / 70", LeftArmPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eRightLegPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            RightLegPlayer -= InDamage;
            printf("������ �����ٸ��� �°�, ������ �Ͼ���ϴ�!\n������ ü�� : %d / 70", RightLegPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            RightLegPlayer -= InDamage;
            printf("������ �����ٸ��� �¾ҽ��ϴ�!\n�����ٸ� ü�� : %d / 70", RightLegPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eLeftLegPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            LeftLegPlayer -= InDamage;
            printf("������ �޴ٸ��� �°�, ������ �Ͼ���ϴ�!\n�޴ٸ� ü�� : %d / 70", LeftLegPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            LeftLegPlayer -= InDamage;
            printf("������ �޴ٸ��� �¾ҽ��ϴ�!\n�޴ٸ� ü�� : %d / 70", LeftLegPlayer);
            IsAlive();
        }
    }
    else
    {
        printf("�����ε�");
    }

}

int Player::BoltGunShot(int EnemyHealth)
{
    for (int i = 0; i < 3; i++)
    {
        int DamageBlotGun = rand() % 21 + 20;
    }
    return 0;
}

int Player::ChainSwordAttack(int EnemyHealth)
{
    for (int i = 0; i < 5; i++)
    {
        int DamageChainSword = rand() & 11 + 10;
    }
    return 0;
}
