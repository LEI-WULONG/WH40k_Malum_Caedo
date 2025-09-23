#include "Boyz.h"

void Boyz::Attack(Player& player)
{
    // 매 공격마다 다른 값 원하면 아래와 같이 재계산:
    // const int damage = rand() % 11 + 20;
    // player.TakeDamagePlayer(damage);

    player.TakeDamagePlayer(AttackPowerEnemy);
}
