#include "Boyz.h"

void Boyz::Attack(Player& player)
{
    // �� ���ݸ��� �ٸ� �� ���ϸ� �Ʒ��� ���� ����:
    // const int damage = rand() % 11 + 20;
    // player.TakeDamagePlayer(damage);

    player.TakeDamagePlayer(AttackPowerEnemy);
}
