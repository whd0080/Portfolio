#pragma once
class Mage : public PlayerUnit
{
public:
	Mage(string name);
	~Mage() {}

	virtual void Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget) override;
	bool MagePassive(int* chant);

private:
	int _chant = 0;
};

