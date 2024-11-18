#pragma once
class Archer : public PlayerUnit
{
public:
	Archer(string name);
	~Archer() { cout << "Archer deleted" << endl; }

	virtual void Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget) override;
	bool ArcherPassive();

private:
	int cost = 200;
};

