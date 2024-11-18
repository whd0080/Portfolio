#pragma once

struct PlayerInfo
{
	weak_ptr<PlayerUnit> p;
	int totalDamage;

	bool operator>(const PlayerInfo& b) const
	{
		if (totalDamage > b.totalDamage)
			return true;
		return false;
	}
};

class BossGoblin : public Monster
{
public:
	BossGoblin(string name);
	~BossGoblin() { cout << "Boss deleted" << endl; }

	virtual void Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget) override;
	virtual void TakeDamage(int amount, shared_ptr<Creature> attacker) override;
	

private:
	void PrintTable();
	list<PlayerInfo> _aggroTable;
	bool Passive();
	
};