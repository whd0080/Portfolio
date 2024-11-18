#include "framework.h"
#include "Archer.h"

Archer::Archer(string name)
	: PlayerUnit(name , 140, 140, 50, 5, 60, 200)
{
}

void Archer::Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget)
{
	if (IsDead())
		return;

	cout << this->Getname() << "�� ����!!" << endl;
	if (AttackHit())
	{
		starget->TakeDamage(this->GetAtk(), shared_from_this());
		cout << starget->Getname() << " ���� " << this->GetAtk() << " �� ������!" << endl;
		starget->PrintStatus();

		cout << "===============================" << endl;
		cout << endl;


		if (ArcherPassive())
		{
			cout << this->Getname() << "�� ���ӻ��!!" << endl;
			Attack(Target(mtarget, mtarget.size()), mtarget);
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

bool Archer::ArcherPassive()
{
	int iActive = rand() % 2;
	if (iActive == 0) return true;
	return false;
}
