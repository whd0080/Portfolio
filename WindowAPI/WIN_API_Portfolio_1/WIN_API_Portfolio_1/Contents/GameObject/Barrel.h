#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetCannon(shared_ptr<class Cannon> cannon) { _cannon = cannon; }

	void SetDirection(Vector dir) { _direction = dir; }
	Vector GetDirection() { return _direction; }

	Vector GetMuzzle() { return _line->_end; }

private:
	shared_ptr<Line> _line;

	float _length = 100.0f;
	Vector _direction = Vector(1, 0);

	// �ܺο��� ������ ���� �����ϰ� ���� ���� weak_ptr�� ����ȴ�.
	weak_ptr<class Cannon> _cannon;
};