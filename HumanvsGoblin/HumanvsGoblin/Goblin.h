#pragma once
class Goblin : public Monster
{
public:
	Goblin(string name);
	~Goblin() { cout << "Goblin deleted" << endl; }
};

