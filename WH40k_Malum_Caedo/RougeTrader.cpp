#include "RougeTrader.h"

bool RougeTrader::SellMed(Player& player)
{
	if (player.Med >= 2)
	{
		printf("\n�޵�ī�� ������ �޵�ī���� �̹� 2�� �̻��Դϴ�. �� �̻� ������ �� �����ϴ�.\n\n");
		return false;
	}
	else if (player.OaksHead < 2)
	{
		printf("\n���� �Ӹ����� �����մϴ�. �޵�ī���� ������ �� �����ϴ�.\n\n");
		return false;
	}
	else
	{
		player.OaksHead -= 2;
		player.Med += 1;
		printf("\n�޵�ī���� �����߽��ϴ�! ���� �޵�ī�� ���� ����: %d\n\n", player.Med);
		return true;
	}
}
