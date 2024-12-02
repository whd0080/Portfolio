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

	// 투사체(Projecttile)
	// 어디서부터 어느 방향(_direction)으로 어떤 속도(_speed)로날아간다.
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
