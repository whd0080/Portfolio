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

	cout << this->Getname() << "의 공격!!" << endl;
	if (AttackHit())
	{
		starget->TakeDamage(this->GetAtk(), shared_from_this());
		cout << starget->Getname() << " 에게 " << this->GetAtk() << " 의 데미지!" << endl;
		starget->PrintStatus();

		cout << "===============================" << endl;
		cout << endl;


		if (ArcherPassive())
		{
			cout << this->Getname() << "의 연속사격!!" << endl;
			Attack(Target(mtarget, mtarget.size()), mtarget);
		}
	}
	else
	{
		cout << "빗나갔다..." << endl;
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
