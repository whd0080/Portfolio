#include "framework.h"
#include "BossGoblin.h"

BossGoblin::BossGoblin(string name) : Monster(name, 22000, 22000, 60, 4, 65)
{
}

void BossGoblin::Attack(shared_ptr<Creature> starget, list<shared_ptr<Creature>> mtarget)
{
	if (_aggroTable.size() == 0)
		return;

	auto iter = std::remove_if(_aggroTable.begin(), _aggroTable.end(), [](const PlayerInfo& info)-> bool
		{
			if (info.p.expired() == false)
			{
				auto player = info.p.lock();

				if (player->IsDead() == true)
					return true;
				else return false;
			}
			else
				return true;
		});

	_aggroTable.erase(iter, _aggroTable.end());

	_aggroTable.sort(greater<PlayerInfo>());

	cout << this->Getname() << "의 공격!!" << endl;
	if (AttackHit())
	{
			if (Passive())
			{
				cout << Getname() << "의 분노의 일격!" << endl;
				int range = 2;

				if (range > _aggroTable.size()) range = _aggroTable.size();

				for (int i = 0; i < range; i++)
				{
					list<PlayerInfo>::iterator Iter = _aggroTable.begin();
					PlayerInfo p = *Iter;
					p.p.lock().get()->TakeDamage(GetAtk() * 2, nullptr);
					
					cout << p.p.lock().get()->Getname() << "에게" << GetAtk() * 2 << "의 데미지!" << endl;
					p.p.lock().get()->PrintStatus();
					if(p.p.lock().get()->IsDead())
						cout << p.p.lock().get()->Getname() << "은(는) 쓰러졌다..." << endl;
				}
				cout << "===============================" << endl;
				cout << endl;
			}
			else
			{
				list<PlayerInfo>::iterator Iter = _aggroTable.begin();
				PlayerInfo p = *Iter;

				p.p.lock().get()->TakeDamage(GetAtk(), nullptr);
				cout << p.p.lock().get()->Getname() << "에게" << GetAtk() * 2 << "의 데미지!" << endl;
				
				p.p.lock().get()->PrintStatus();
				if (p.p.lock().get()->IsDead())
					cout << p.p.lock().get()->Getname() << "은(는) 쓰러졌다..." << endl;
				cout << "===============================" << endl;
				cout << endl;
			}
	}
	else
	{
		cout << starget->Getname() << "은(는) 공격을 피했다!!" << endl;
		starget->PrintStatus();
		cout << "===============================" << endl;
		cout << endl;
	}

	PrintTable();
}

void BossGoblin::TakeDamage(int amount, shared_ptr<Creature> attacker)
{
	Creature::TakeDamage(amount, nullptr);

	auto Iter = std::find_if(_aggroTable.begin(), _aggroTable.end(), [attacker](const PlayerInfo& info)->bool
	{
			if (info.p.lock().get() == attacker.get())
			{
				return true;
			}
			
			return false;
	});

	if (Iter == _aggroTable.end())
	{
		PlayerInfo info = { dynamic_pointer_cast<PlayerUnit>(attacker), amount };
		_aggroTable.push_back(info);
	}
	else
	{
		Iter->totalDamage += amount;
	}

}

bool BossGoblin::Passive()
{
	if (this->GetHp() < this->GetMaxHp() / 2) return true;
	return false;
}

void BossGoblin::PrintTable()
{
	for (auto info : _aggroTable)
	{
		PlayerInfo p = info;
		if (p.p.expired() == false)
		{
			auto temp = info.p.lock();
			cout << temp->Getname() << " /Total Damage: " << info.totalDamage << endl;
		}
	}
}
