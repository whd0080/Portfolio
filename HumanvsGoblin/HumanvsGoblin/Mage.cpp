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

	cout << this->Getname() << "의 공격!!" << endl;
	if (AttackHit())
	{
		if (MagePassive(&_chant))
		{
			cout << this->Getname() << "은(는) 마법을 사용했다." << endl;
			starget->TakeDamage(this->GetAtk() * 3, shared_from_this());
			cout << starget->Getname() << "에게 " << this->GetAtk() << "의 데미지!" << endl;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
		}
		else
		{
			starget->TakeDamage(this->GetAtk(), shared_from_this());
			cout << starget->Getname() << "에게 " << this->GetAtk() << "의 데미지!" << endl;
			_chant++;
			starget->PrintStatus();
			cout << "===============================" << endl;
			cout << endl;
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
		cout << this->Getname() << "이(가) 마법을 영창하는 중..." << endl;
		return false;
	}
}
