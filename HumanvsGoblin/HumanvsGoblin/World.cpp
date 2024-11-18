#include "framework.h"

void World::Init()
{
	Player p;

	cout << "스테이지를 선택해 주세요." << endl << endl;
	cout << "1. Stage1 : 고블린 10마리		지원금 : 1000원" << endl;
	cout << "2. Stage2 : 보스고블린 1마리	지원금 : 2500원" << endl;
	cout << "1, 2 외의 숫자를 입력하면 종료됩니다." << endl;
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
		cout << "게임을 종료합니다." << endl;
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
		
		cout << "고용할 용병을 고르세요 : " << endl;
		cout << "1. 전사(비용 : 100원)" << endl;
		cout << "2. 궁수(비용 : 200원)" << endl;
		cout << "3. 마법사(비용 : 250원)" << endl;
		cout << "0. 출격 " << endl;
		cout << "남은 비용 : " << _money << endl;
		cout << " : ";

		iSelectJob = p.Input();

		if (iSelectJob == 0)
		{
			cout << "현재의 용병들로 출격합니다." << endl;
			break;
		}

		switch (iSelectJob)
		{
		case 1:
		{
			shared_ptr<Knight> k = make_shared<Knight>("");

			if (_money < k->GetCost())
			{
				cout << " 더 이상 고용할 돈이 없습니다." << endl << endl;
				break;
			}
			
			cout << "===========전사고용===========" << endl;
			cout << "구매할 용병의 수를 알려주세요." << endl;
			cout << _money / k->GetCost() << "명 만큼 고용가능" << endl;
			cout << " : ";
			

			while (true)
			{
				iEmploy = p.Input();
				if ((iEmploy * k->GetCost()) <= _money) break;
				cout << "금액이 모자릅니다." << endl;
				cout << "다시 입력해주세요." << endl;
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
				cout << " 더 이상 고용할 돈이 없습니다." << endl << endl;
				break;
			}
			cout << "===========궁수고용===========" << endl;
			cout << "구매할 용병의 수를 알려주세요." << endl;
			cout << _money / a->GetCost() << "명 만큼 고용가능" << endl;
			cout << " : ";

			while (true)
			{
				iEmploy = p.Input();
				if ((iEmploy * a->GetCost()) <= _money) break;
				cout << "금액이 모자릅니다." << endl;
				cout << "다시 입력해주세요." << endl;
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
				cout << " 더 이상 고용할 돈이 없습니다." << endl << endl;
				break;
			};
			cout << "===========마법사고용==========" << endl;
			cout << "구매할 용병의 수를 알려주세요." << endl;
			cout << _money / m->GetCost() << "명 만큼 고용가능" << endl;
			cout << " : ";

			while (true)
			{
				iEmploy = p.Input();
				if ((iEmploy * m->GetCost()) <= _money) break;
				cout << "금액이 모자릅니다." << endl;
				cout << "다시 입력해주세요." << endl;
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
			cout << "1 ~ 3 사이의 수를 입력하세요." << endl;
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
		cout << "전투에서 승리했다!" << endl;
		return true;
	}

	_player.remove_if([](shared_ptr<Creature> p) {return p->IsDead() == true; });
		

	if (_player.empty())
	{
		cout << "전투에서 패배했다..." << endl;
		return true;
	}


	return false;
}

int World::GetSize()
{
	return this->_player.size();
}
