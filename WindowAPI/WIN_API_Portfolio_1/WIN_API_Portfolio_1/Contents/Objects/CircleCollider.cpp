#include "framework.h"
#include "RectCollider.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	: _radius(radius)
{
	_center = center;

	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);

	SetGreen();
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
	// TODO
}

void CircleCollider::Render(HDC hdc)
{
	int left = _center.x - _radius;
	int right = _center.x + _radius;
	int top = _center.y - _radius;
	int bottom = _center.y + _radius;

	SelectObject(hdc, _colors[_curColor]);

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(const Vector& pos) const
{
	float length = (pos - _center).Length();

	return length < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	float radiusSum = _radius + other->Radius();
	float length = (other->Center() - _center).Length();

	return length < radiusSum;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other) const
{
	// AABB
	float closetX = max(other->Left(), min(_center.x, other->Right()));
	float closetY = max(other->Top(), min(_center.y, other->Bottom()));

	float distanceX = _center.x - closetX;
	float distanceY = _center.y - closetY;
	float distanceSquared = distanceX * distanceX + distanceY * distanceY;


	return distanceSquared <= (_radius * _radius);

	// OBB
	/*Vector centerDistance = _center - other->Center();

	Vector axisX = other->AxisX();
	Vector axisY = other->AxisY();

	float projectionX = centerDistance.Dot(axisX);
	float projectionY = centerDistance.Dot(axisY);

	float clampedProjectionX = max(-other->HalfSize().x, min(projectionX, other->HalfSize().x));
	float clampedProjectionY = max(-other->HalfSize().y, min(projectionY, other->HalfSize().y));

	Vector closestPoint = other->Center() + axisX * clampedProjectionX + axisY * clampedProjectionY;

	float distanceSquared = (_center - closestPoint).LengthSquared();

	return distanceSquared <= (_radius * _radius);*/
}