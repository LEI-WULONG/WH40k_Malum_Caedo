#include "RougeTrader.h"

bool RougeTrader::SellMed(Player& player)
{
	if (player.Med >= 2)
	{
		printf("�޵�ī�� ������ �޵�ī���� �̹� 2�� �̻��Դϴ�. �� �̻� ������ �� �����ϴ�.\n");
		return false;
	}
	else if (player.OaksHead < 2)
	{
		printf("���� �Ӹ����� �����մϴ�. �޵�ī���� ������ �� �����ϴ�.\n");
		return false;
	}
	else
	{
		player.OaksHead -= 2;
		player.Med += 1;
		printf("�޵�ī���� �����߽��ϴ�! ���� �޵�ī�� ���� ����: %d\n", player.Med);
		return true;
	}
}
