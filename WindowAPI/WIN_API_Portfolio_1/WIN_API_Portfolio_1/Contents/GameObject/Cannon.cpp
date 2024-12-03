#include "framework.h"
#include "Barrel.h"
#include "Ball.h"

#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(100, 600), 30);
	_barrel = make_shared<Barrel>();

	// ball ����
	for (int i = 0; i < _poolCount; i++)
	{
		auto ball = make_shared<Ball>();

		_ballPool.push_back(ball);
	}
}

Cannon::~Cannon()
{
}

// CPU
void Cannon::Update()
{
	_body->Update();
	_barrel->Update();

	for (auto ball : _ballPool)
	{
		ball->Update();
	}

	InputMove(); // �Է��ؼ� �����̰�
	InputBarrelRotation(); // �Է����� �ѽ� ���� ����
	Fire();
	
}

// GPU
void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto ball : _ballPool)
	{
		ball->Render(hdc);
	}
}

void Cannon::Fire()
{
	// 0b 1000 0000 0000 0001
	// 0b 0111 0000 0000 0001
	clock_t currentFireTime = clock();

	if (currentFireTime - _lastFireTime < 1000)
		return;

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8001)
	{
		auto iter = std::find_if(_ballPool.begin(), _ballPool.end(), [](const shared_ptr<Ball>& ball) -> bool
			{
				if (ball->IsActive() == false)
					return true;
				return false;
			});

		if (iter == _ballPool.end()) return;

		(*iter)->Fire(_barrel->GetMuzzle(), _barrel->GetDirection());

		_lastFireTime = currentFireTime;
	}
}

void Cannon::InputMove()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		_body->Center().x -= 3;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		_body->Center().x += 3;
}

void Cannon::InputBarrelRotation()
{
	Vector dir = mousePos - _body->Center();
	dir.Normalize();

	_barrel->SetDirection(dir);
}