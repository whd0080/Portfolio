#include "framework.h"
#include "Knight.h"

Knight::Knight(string name)
	: PlayerUnit(name, 220, 220, 80, 2, 90, 100)
{
}

void Knight::Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget)
{
	if (IsDead())
		return;

	cout << Getname() << "의 공격!!" << endl;
	if (AttackHit())
	{
		if (KnightPassive())
		{
			cout << Getname() << "은(는) 혼신의 힘을 발휘했다." << endl;
			starget->TakeDamage(GetAtk() * 2, shared_from_this());
			cout << starget->Getname() << "에게 " << GetAtk() * 2 << "의 데미지!" << endl;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
		else
		{
			starget->TakeDamage(GetAtk(), shared_from_this());
			cout << starget->Getname() << "에게 " << GetAtk() << "의 데미지!" << endl;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << starget->Getname() << "이(가) 공격을 피했다." << endl;
		starget->PrintStatus();
		cout << "===============================" << endl;
		cout << endl;
	}
}

bool Knight::KnightPassive()
{
	if (GetHp() / GetMaxHp() <= 0.5) return true;
	return false;
}
