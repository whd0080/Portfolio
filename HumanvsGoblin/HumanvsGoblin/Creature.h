#pragma once
class Creature : public enable_shared_from_this<Creature>
{
public:
	int _index;

	Creature();
	Creature(string name, int hp, int maxhp, int atk, int speed, int hit);
	~Creature() { cout << "Creature deleted" << endl; }

	virtual void Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget);
	shared_ptr<Creature> Target(list<shared_ptr<Creature>> creature, int i);
	virtual void TakeDamage(int amount, shared_ptr<Creature> attacker);
	void PrintStatus();

	string Getname();
	int GetHp();
	int GetMaxHp();
	int GetAtk();

	bool AttackHit();
	bool IsDead();

private:
	string _name;
	int _hp;
	int _maxhp;
	int _atk;
	int _speed;
	int _hit;
};

