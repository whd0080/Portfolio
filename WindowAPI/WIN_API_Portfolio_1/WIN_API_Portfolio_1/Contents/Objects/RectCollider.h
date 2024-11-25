#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size, float angle);
	~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Rotation(float rotation) { _angle += rotation; }
	void ProjectOntoAxis(const Vector& axis, float& min, float& max);

	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }

	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) const override;

	Vector AxisX() const { return Vector(cos(_angle), sin(_angle)); }
	Vector AxisY() const { return Vector(-sin(_angle), cos(_angle)); }

	Vector HalfSize() { return _halfSize; }

	vector<Vector> GetCorners() const;

private:
	Vector		 _halfSize;
	float		 _angle = 0.0f;
};