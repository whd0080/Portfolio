#pragma once
class PlayerUnit : public Creature
{
public:
	PlayerUnit(string name, int hp, int maxhp, int atk, int speed, int hit, int cost);
	~PlayerUnit() { cout << "PlayerUnit deleted" << endl; }
	
	int GetCost();

private:
	int _cost;
};