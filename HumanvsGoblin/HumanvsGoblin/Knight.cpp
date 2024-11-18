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

	cout << Getname() << "�� ����!!" << endl;
	if (AttackHit())
	{
		if (KnightPassive())
		{
			cout << Getname() << "��(��) ȥ���� ���� �����ߴ�." << endl;
			starget->TakeDamage(GetAtk() * 2, shared_from_this());
			cout << starget->Getname() << "���� " << GetAtk() * 2 << "�� ������!" << endl;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
		else
		{
			starget->TakeDamage(GetAtk(), shared_from_this());
			cout << starget->Getname() << "���� " << GetAtk() << "�� ������!" << endl;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << starget->Getname() << "��(��) ������ ���ߴ�." << endl;
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
