#pragma once
// 1. ��
// 2. ��Ӱ��� ����
// 3. �浹ó��(AABB, OBB)
class RectCollider;


// Collider : �浹ü
class CircleCollider : public Collider
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	float& Radius() { return _radius; }

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) const override;

private:
	float		 _radius;
};

