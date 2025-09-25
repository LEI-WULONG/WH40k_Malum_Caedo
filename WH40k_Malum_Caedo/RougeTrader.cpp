#include "RougeTrader.h"

bool RougeTrader::SellMed(Player& player)
{
	if (player.Med >= 2)
	{
		printf("메디카에 소지한 메디카에가 이미 2개 이상입니다. 더 이상 구매할 수 없습니다.\n");
		return false;
	}
	else if (player.OaksHead < 2)
	{
		printf("옼스 머리통이 부족합니다. 메디카에를 구매할 수 없습니다.\n");
		return false;
	}
	else
	{
		player.OaksHead -= 2;
		player.Med += 1;
		printf("메디카에를 구매했습니다! 현재 메디카에 소지 갯수: %d\n", player.Med);
		return true;
	}
}
