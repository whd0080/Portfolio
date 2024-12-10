#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector(0, 0), 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (_isActive == false)	return;

	_ball->Update();

	// ������(Projectile)
	// ��𼭺��� ��� ����(_direction)���� � �ӵ�(_speed)�� ���ư���.
	_ball->Center() += _direction * _speed;

	_gravity += 1.0f;
	_ball->Center().y += _gravity;
	if (IsOut() == true) _isActive = false;
}

void Ball::Render(HDC hdc)
{
	if (_isActive == false) return;

	_ball->Render(hdc);
}

void Ball::Fire(Vector pos, Vector dir)
{
	_isActive = true;
	_gravity = 0.0f;

	SetPos(pos);
	SetDirection(dir);
}

bool Ball::IsOut()
{
	int x = _ball->Center().x;
	int y = _ball->Center().y;

	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT)
		return true;

	return false;
}