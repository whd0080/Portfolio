#pragma once
#include "Barrel.h"
#include "Ball.h"

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void PostInitilize() { Ready(); }
	void Update();
	void Render(HDC hdc);

	const Vector& GetCenter() { return _body->Center(); }

	void Fire();

	bool IsFireReady()
	{
		if (_myturn == false)
			return false;

		_fireTime += 0.01f;
		if (_fireTime > _fireDelay && GetAsyncKeyState(VK_SPACE))
		{
			_fireTime = 0.0f;
			return true;
		}

		return false;
	}

	bool IsDamageReady()
	{
		_damageTime += 0.01f;
		if (_damageTime >= _damageDelay)
			return true;
		return false;
	}

	void SetCenter(Vector vector) { _body->Center() = vector; }
	void SetTurn(bool turn) { _myturn = turn; }
	void MyTurn(shared_ptr<Cannon> other);
	bool GetHit(const vector<shared_ptr<Ball>>& otherball);
	vector<shared_ptr<Ball>> GetBall() { return _ballPool; }
	void TakeDamage();
	shared_ptr<CircleCollider> GetCircle() { return _body; }
	bool IsDead() 
	{
		if (_hp <= 0)
		{
			_hp = 0;
			return true;
		}
		return false;
	}

private:
	void Ready() { _barrel->SetCannon(shared_from_this()); }
	// 입력으로 좌우로 움직이게 만드는 함수
	void InputMove();
	// 입력으로 총신의 각도가 +,-가 되게 만드는 함수
	void InputBarrelRotation();

private:
	int _hp = 3;
	bool _myturn = true;
	shared_ptr<CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;

	int _poolCount = 30;
	vector<shared_ptr<class Ball>> _ballPool;

	float _fireDelay = 1.0f; // 1초를 정확히 할 수 있을까? X
	float _fireTime = 0.0f;

	float _damageDelay = 1.0f;
	float _damageTime = 0.0f;
};