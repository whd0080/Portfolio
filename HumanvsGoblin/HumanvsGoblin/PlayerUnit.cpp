#include "framework.h"
#include "PlayerUnit.h"

PlayerUnit::PlayerUnit(string name, int hp, int maxhp, int atk, int speed, int hit, int cost)
	: Creature(name, hp, maxhp, atk, speed, hit), _cost(cost)
{
}

int PlayerUnit::GetCost()
{
	return _cost;
}
