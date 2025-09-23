#include "Player.h"

void Player::UsingMed()
{
    if (Med == 0)
    {
        printf("소지하고 있는 메디카에가 없습니다.\n");
    }
    else
    {
        Med--;
        printf("메디카에를 사용했습니다. 보유 메디카에 : %d / 2", Med);
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
        printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : 볼터\n----- 체력 -----\n", Name.c_str(), OaksHead);
        printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("최종 건강 상태 : 심각함");
    }
    else if ((PlayerTotalHealth <= PlayerWound) && (MyWeapon == WeaponType::Bolter))
    {
        printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : 볼터\n----- 체력 -----\n", Name.c_str(), OaksHead);
        printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("최종 건강 상태 : 부상");
    }
    else if ((PlayerTotalHealth <= PlayerWoundHealty) && (MyWeapon == WeaponType::Bolter))
    {
        printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : 볼터\n----- 체력 -----\n", Name.c_str(), OaksHead);
        printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("최종 건강 상태 : 양호");
    }

    if ((PlayerTotalHealth <= PlayerWoundAlmostDeath) && (MyWeapon == WeaponType::ChainSword))
    {
        printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : 체인소드\n----- 체력 -----\n", Name.c_str(), OaksHead);
        printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("최종 건강 상태 : 심각함");
    }
    else if ((PlayerTotalHealth <= PlayerWound) && (MyWeapon == WeaponType::ChainSword))
    {
        printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : 체인소드\n----- 체력 -----\n", Name.c_str(), OaksHead);
        printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("최종 건강 상태 : 부상");
    }
    else if ((PlayerTotalHealth <= PlayerWoundHealty) && (MyWeapon == WeaponType::ChainSword))
    {
        printf("이름 : %s\n소지금 : 머리통 %d개\n장착 무기 : 체인소드\n----- 체력 -----\n", Name.c_str(), OaksHead);
        printf("머리 : %d\n몸통 : %d\n오른팔 : %d\n왼팔 : %d\n오른다리 : %d\n왼다리 : \n\n", HeadPlayer, ThoraxPlayer,
            RightArmPlayer, LeftArmPlayer, RightLegPlayer, LeftLegPlayer);
        printf("최종 건강 상태 : 양호");
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
        printf("버그인듯");
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
        printf("공격을 피했습니다!\n");
    }

    if (static_cast<int>(BodyPartsPlayer::eHeadPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            HeadPlayer -= InDamage;
            printf("적에게 머리를 맞고, 출혈이 일어났습니다!\n머리 체력 : %d / 45", HeadPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            HeadPlayer -= InDamage;
            printf("적에게 머리를 맞았습니다!\n머리 체력 : %d / 45", HeadPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eThoraxPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            ThoraxPlayer -= InDamage;
            printf("적에게 몸통을 맞고, 출혈이 일어났습니다!\n몸통 체력 : %d / 90", ThoraxPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            ThoraxPlayer -= InDamage;
            printf("적에게 몸통을 맞았습니다!\n몸통 체력 : %d / 90", ThoraxPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eRightArmPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            RightArmPlayer -= InDamage;
            printf("적에게 오른팔을 맞고, 출혈이 일어났습니다!\n오른팔 체력 : %d / 70", RightArmPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            RightArmPlayer -= InDamage;
            printf("적에게 오른팔을 맞았습니다!\n오른팔 체력 : %d / 70", RightArmPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eLeftArmPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            LeftArmPlayer -= InDamage;
            printf("적에게 왼팔을 맞고, 출혈이 일어났습니다!\n오른팔 체력 : %d / 70", LeftArmPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            LeftArmPlayer -= InDamage;
            printf("적에게 왼팔을 맞았습니다!\n왼팔 체력 : %d / 70", LeftArmPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eRightLegPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            RightLegPlayer -= InDamage;
            printf("적에게 오른다리를 맞고, 출혈이 일어났습니다!\n오른팔 체력 : %d / 70", RightLegPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            RightLegPlayer -= InDamage;
            printf("적에게 오른다리를 맞았습니다!\n오른다리 체력 : %d / 70", RightLegPlayer);
            IsAlive();
        }
    }
    else if (static_cast<int>(BodyPartsPlayer::eLeftLegPlayer) == AttackRollBodyPart)
    {
        if (BleedingDodgeChance == BleedingRoll)
        {
            LeftLegPlayer -= InDamage;
            printf("적에게 왼다리를 맞고, 출혈이 일어났습니다!\n왼다리 체력 : %d / 70", LeftLegPlayer);
            IsBleeding = true;
            IsAlive();
        }
        else
        {
            LeftLegPlayer -= InDamage;
            printf("적에게 왼다리를 맞았습니다!\n왼다리 체력 : %d / 70", LeftLegPlayer);
            IsAlive();
        }
    }
    else
    {
        printf("버그인듯");
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
