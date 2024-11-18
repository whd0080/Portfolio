#pragma once
class Knight : public PlayerUnit
{
public:
	Knight(string name);
	~Knight() { cout << "Knight deleted" << endl; }

	virtual void Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget) override;

	bool KnightPassive();
};

