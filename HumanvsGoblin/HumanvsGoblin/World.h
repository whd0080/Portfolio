#pragma once
class World
{
public:
	World()
	{
		Init();
	}
	~World() { cout << "World deleted" << endl; }

	void Init();
	void BuyPlayerUnit();
	void Stage1();
	void Stage2();

	void Update();
	bool End();

	int GetSize();

private:
	list<shared_ptr<Creature>> _player;
	list<shared_ptr<Creature>> _monster;

	int _pase = 1;
	int _money;
	int _index;
	bool IsStart;
};

