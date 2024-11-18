#include "framework.h"
#include "Mage.h"

Mage::Mage(string name)
	: PlayerUnit(name, 100, 100, 80, 2, 85, 250)
{
}

void Mage::Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget)
{
	if (IsDead())
		return;

	cout << this->Getname() << "�� ����!!" << endl;
	if (AttackHit())
	{
		if (MagePassive(&_chant))
		{
			cout << this->Getname() << "��(��) ������ ����ߴ�." << endl;
			starget->TakeDamage(this->GetAtk() * 3, shared_from_this());
			cout << starget->Getname() << "���� " << this->GetAtk() << "�� ������!" << endl;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
		else
		{
			starget->TakeDamage(this->GetAtk(), shared_from_this());
			cout << starget->Getname() << "���� " << this->GetAtk() << "�� ������!" << endl;
			_chant++;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "��������..." << endl;
		starget->PrintStatus();
		cout << "===============================" << endl;
		cout << endl;
	}
}

bool Mage::MagePassive(int* chant)
{
	if (*chant == 1)
	{
		*chant = 0;
		return true;
	}
	else
	{
		*chant = 1;
		cout << this->Getname() << "��(��) ������ ��â�ϴ� ��..." << endl;
		return false;
	}
}
