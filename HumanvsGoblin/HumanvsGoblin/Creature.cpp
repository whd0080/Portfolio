#include "framework.h"

Creature::Creature() : _name(""), _hp(0), _maxhp(0), _atk(0), _speed(0), _hit(0)
{
}

Creature::Creature(string name, int hp, int maxhp, int atk, int speed, int hit)
	: _name(name), _hp(hp), _maxhp(maxhp), _atk(atk), _speed(speed), _hit(hit)
{
}

void Creature::Attack(shared_ptr<Creature> starget ,list<shared_ptr<Creature>> mtarget)
{
	if (IsDead())
		return;

	cout << this->Getname() << "의 공격!!" << endl;
	if (AttackHit())
	{
		starget->TakeDamage(_atk, nullptr);
		cout << starget->Getname() << " 에게 " << this->_atk << "의 데미지!" << endl;
		starget->PrintStatus();
		cout << "===============================" << endl;
		cout << endl;
	}
	else
	{
		cout << starget->_name << "은(는) 공격을 피했다." << endl;
	}
}

shared_ptr<Creature> Creature::Target(list<shared_ptr<Creature>> creature, int i)
{
	int Index = rand() % i;

	shared_ptr<Creature> c;
	list<shared_ptr<Creature>>::iterator Iter = creature.begin();

	advance(Iter, Index);
	c = *Iter;

	return c;
}

void Creature::TakeDamage(int amount, shared_ptr<Creature> attacker)
{
	_hp -= amount;

	if (_hp <= 0)
		_hp = 0;
}

void Creature::PrintStatus()
{
	cout << "[" << this->_name << "]" << endl;
	cout << "HP : " << this->_maxhp << " / " << this->_hp << endl;
}

string Creature::Getname()
{
	return _name;
}

int Creature::GetHp()
{
	return _hp;
}

int Creature::GetMaxHp()
{
	return _maxhp;
}

int Creature::GetAtk()
{
	return _atk;
}

bool Creature::AttackHit()
{
	int iHit = rand() % 101;
	
	if (iHit < this->_hit)
		return true;
	return false;
}

bool Creature::IsDead()
{
	return _hp <= 0;
}
