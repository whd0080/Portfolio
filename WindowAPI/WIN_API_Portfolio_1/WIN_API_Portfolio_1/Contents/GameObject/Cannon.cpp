#include "framework.h"
#include "Barrel.h"
#include "Ball.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(100, 600), 30);
	_barrel = make_shared<Barrel>();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	InputMove(); // �Է��ؼ� �����̰�
	InputBarrelRotation(); // �Է����� �ѽ� ���� ����
	Fire();

	_body->Update();
	_barrel->Update();
	BallErase();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (const auto& ball : _balls)
	{
		ball->Render(hdc);
	}
}

void Cannon::Fire()
{
	// 0b 1000 0000 0000 0001
	// 0b 0111 0000 0000 0001
	Vector dir = mousePos - _body->Center();
	dir.Normalize();

	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		auto ball = make_shared<Ball>();
		ball->SetCenter(_body->Center() + dir * 95.0f); // �� ���Ű� ���� ���̷� �Է��ߴµ� �ٸ� ���̰� �������� ����...
		ball->SetDirection(dir);
		_balls.push_back(ball);
	}
}

void Cannon::BallErase()
{
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	for (auto Iter = _balls.begin(); Iter != _balls.end();)
	{
		(*Iter)->Update();

		// ȭ�� ������ ���� ������ ����
		if ((*Iter)->GetCenter().x < 0 || (*Iter)->GetCenter().x > width ||
			(*Iter)->GetCenter().y > height)
		{
			Iter = _balls.erase(Iter);
		}
		else
		{
			++Iter;
		}
	}

	_balls.shrink_to_fit();
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