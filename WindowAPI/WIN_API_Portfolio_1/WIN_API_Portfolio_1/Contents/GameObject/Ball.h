#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector center);
	void SetDirection(Vector dir) { _directrion = dir; }

	Vector GetCenter() { return _ball->Center(); }

private:
	shared_ptr<CircleCollider> _ball;
	Vector _directrion = Vector(1,0);
	float _speed = 10.0f;
	float _gravity = 0.0f;
};

