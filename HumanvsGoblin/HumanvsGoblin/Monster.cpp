#include "framework.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int maxhp, int atk, int speed, int hit)
	: Creature(name, hp, maxhp, atk, speed, hit)
{
}
