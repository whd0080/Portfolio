#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector(-10000, 0), 5);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	_ball->Update();

	// ����ü(Projecttile)
	// ��𼭺��� ��� ����(_direction)���� � �ӵ�(_speed)�γ��ư���.
	_ball->Center() += _directrion * _speed;
	_ball->Center().y += _gravity;
	_gravity += 0.08f;
}

void Ball::Render(HDC hdc)
{
	_ball->Render(hdc);
}

void Ball::SetCenter(Vector center)
{
	_gravity = 0.0f;
	_ball->Center() = center;
}
