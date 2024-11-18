#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int maxhp, int atk, int speed, int hit);
	~Monster() { cout << "Monster deleted" << endl; }
};

