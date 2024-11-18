#include "framework.h"

void World::Init()
{
	Player p;

	cout << "���������� ������ �ּ���." << endl << endl;
	cout << "1. Stage1 : ��� 10����		������ : 1000��" << endl;
	cout << "2. Stage2 : ������� 1����	������ : 2500��" << endl;
	cout << "1, 2 ���� ���ڸ� �Է��ϸ� ����˴ϴ�." << endl;
	cout << " : ";
	
	switch (p.Input())
	{
	case 1:
	{
		Stage1();
		_money = 1000;
		IsStart = true;
		BuyPlayerUnit();
		break;
	}
	case 2:
	{
		Stage2();
		_money = 2500;
		IsStart = true;
		BuyPlayerUnit();
		break;
	}
	default:
	{
		cout << "������ �����մϴ�." << endl;
		IsStart = false;
		break;
	}
	}
}

void World::BuyPlayerUnit()
{
	Player p;
	int iEmploy;

	while (true)
	{
		int iSelectJob;
		
		cout << "����� �뺴�� ������ : " << endl;
		cout << "1. ����(��� : 100��)" << endl;
		cout << "2. �ü�(��� : 200��)" << endl;
		cout << "3. ������(��� : 250��)" << endl;
		cout << "0. ��� " << endl;
		cout << "���� ��� : " << _money << endl;
		cout << " : ";

		iSelectJob = p.Input();

		if (iSelectJob == 0)
		{
			cout << "������ �뺴��� ����մϴ�." << endl;
			break;
		}

		switch (iSelectJob)
		{
		case 1:
		{
			shared_ptr<Knight> k = make_shared<Knight>("");

			if (_money < k->GetCost())
			{
				cout << " �� �̻� ����� ���� �����ϴ�." << endl << endl;
				break;
			}
			
			cout << "===========������===========" << endl;
			cout << "������ �뺴�� ���� �˷��ּ���." << endl;
			cout << _money / k->GetCost() << "�� ��ŭ ��밡��" << endl;
			cout << " : ";
			

			while (true)
			{
				iEmploy = p.Input();
				if ((iEmploy * k->GetCost()) <= _money) break;
				cout << "�ݾ��� ���ڸ��ϴ�." << endl;
				cout << "�ٽ� �Է����ּ���." << endl;
				cout << " : ";
			}

			for (int i = 0; i < iEmploy; i++)
			{
				auto player = make_shared<Knight>("Knight" + to_string(i));
				_player.push_back(player);
				_money -= k->GetCost();
				
			}
			break;
		}
		case 2:
		{
			shared_ptr<Archer> a = make_shared<Archer>("");
			if (_money < a->GetCost())
			{
				cout << " �� �̻� ����� ���� �����ϴ�." << endl << endl;
				break;
			}
			cout << "===========�ü����===========" << endl;
			cout << "������ �뺴�� ���� �˷��ּ���." << endl;
			cout << _money / a->GetCost() << "�� ��ŭ ��밡��" << endl;
			cout << " : ";

			while (true)
			{
				iEmploy = p.Input();
				if ((iEmploy * a->GetCost()) <= _money) break;
				cout << "�ݾ��� ���ڸ��ϴ�." << endl;
				cout << "�ٽ� �Է����ּ���." << endl;
				cout << " : ";
			}

			for (int i = 0; i < iEmploy; i++)
			{
				auto player = make_shared<Archer>("Archer" + to_string(i));
				_player.push_back(player);
				_money -= a->GetCost();
			}
			break;
		}
		case 3:
		{
			shared_ptr<Mage> m = make_shared<Mage>("");
			if (_money < m->GetCost())
			{
				cout << " �� �̻� ����� ���� �����ϴ�." << endl << endl;
				break;
			};
			cout << "===========��������==========" << endl;
			cout << "������ �뺴�� ���� �˷��ּ���." << endl;
			cout << _money / m->GetCost() << "�� ��ŭ ��밡��" << endl;
			cout << " : ";

			while (true)
			{
				iEmploy = p.Input();
				if ((iEmploy * m->GetCost()) <= _money) break;
				cout << "�ݾ��� ���ڸ��ϴ�." << endl;
				cout << "�ٽ� �Է����ּ���." << endl;
				cout << " : ";
			}

			for (int i = 0; i < iEmploy; i++)
			{
				auto player = make_shared<Mage>("Mage" + to_string(i));
				_player.push_back(player);
				_money -= m->GetCost();
			}

			break;
		}
		default:
			cout << "1 ~ 3 ������ ���� �Է��ϼ���." << endl;
			break;
		}
		
	}

}

void World::Stage1()
{
	for (int i = 0; i < 6; i++)
	{
		auto monster = make_shared<Goblin>("Goblin" + to_string(i + 1));
		_monster.push_back(monster);
	}

	list<shared_ptr<Creature>>::iterator Iter = _monster.begin();
	cout << "=========== 1 Stage =============" << endl;
	for (Iter; Iter != _monster.end(); Iter++)
	{
		shared_ptr<Creature> c = *Iter;
		c->PrintStatus();
	}
	cout << "=================================" << endl;
}

void World::Stage2()
{
	auto monster = make_shared<BossGoblin>("BossGoblin");
	_monster.push_back(monster);
	shared_ptr<Creature> c = *_monster.begin();
	cout << "=========== 2 Stage =============" << endl;
	c->PrintStatus();
	cout << "=================================" << endl;
}

void World::Update()
{
	list<shared_ptr<Creature>>::iterator pIter = _player.begin();
	list<shared_ptr<Creature>>::iterator mIter = _monster.begin();
	shared_ptr<Creature> p = *pIter;
	shared_ptr<Creature> m = *mIter;

	cout << "============ " << _pase << "Pase ============ = " << endl << endl;
	
	for (auto player : _player)
	{
		p = *pIter;
		p->Attack(p->Target(_monster, _monster.size()),_monster);
		pIter++;
	}

	for (auto monster : _monster)
	{
		shared_ptr<Creature> target;
		m = *mIter;
		m->Attack(m->Target(_player, _player.size()), _player);
		mIter++;
	}
}

bool World::End()
{
	_monster.remove_if([](shared_ptr<Creature> m) {return m->IsDead() == true; });

	if (_monster.empty())
	{
		cout << "�������� �¸��ߴ�!" << endl;
		return true;
	}

	_player.remove_if([](shared_ptr<Creature> p) {return p->IsDead() == true; });
		

	if (_player.empty())
	{
		cout << "�������� �й��ߴ�..." << endl;
		return true;
	}


	return false;
}

int World::GetSize()
{
	return this->_player.size();
}
