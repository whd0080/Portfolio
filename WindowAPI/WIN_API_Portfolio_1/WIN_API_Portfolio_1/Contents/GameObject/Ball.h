#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(const Vector& pos) { _ball->Center() = pos; }
	const Vector& GetPos() { return _ball->Center(); }
	void SetDirection(const Vector& dir) { _direction = dir.NormalVector(); }

	void Fire(Vector pos, Vector dir);

	bool IsActive() { return _isActive; }
	bool IsOut();

	shared_ptr<CircleCollider> GetBall() { return _ball; }

	void IsHit(shared_ptr<class CircleCollider> cannon)
	{
		if (_ball->IsCollision(cannon))
		{
			_isActive = false;
			this->SetPos(Vector(0, 0));
		}
	}

private:
	bool _isActive = false;
	shared_ptr<CircleCollider> _ball;
	Vector _direction = Vector(1, 0);
	float _speed = 30.0f;;
	float _gravity = 0.0f;
};