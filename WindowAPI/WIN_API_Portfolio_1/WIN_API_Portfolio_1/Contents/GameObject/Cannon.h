#pragma once
#include "Barrel.h"

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	const Vector& GetCenter() { return _body->Center(); }

	void Fire();
	void Ready() { _barrel->SetCannon(shared_from_this()); }

private:
	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;

	int _poolCount = 30;
	vector<shared_ptr<class Ball>> _ballPool;

	clock_t _lastFireTime;
};