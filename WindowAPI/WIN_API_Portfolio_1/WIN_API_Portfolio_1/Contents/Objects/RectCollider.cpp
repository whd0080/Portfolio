#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size, float angle)
	: _halfSize(size * 0.5f), _angle(angle * PI / 180.f)
{
	_center = center;

	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
	// TODO... 
	if (_angle >= 2 * PI)
		_angle -= 2 * PI;
	if (_angle < 0)
		_angle += 2 * PI;
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);

	auto corners = GetCorners();
	MoveToEx(hdc, corners[0].x, corners[0].y, nullptr);
	for (size_t i = 1; i < corners.size(); ++i) {
		LineTo(hdc, corners[i].x, corners[i].y);
	}
	LineTo(hdc, corners[0].x, corners[0].y);
}

vector<Vector> RectCollider::GetCorners() const
{
	Vector xAxis = AxisX() * _halfSize.x;
	Vector yAxis = AxisY() * _halfSize.y;

	return
	{
		_center + xAxis + yAxis,
		_center - xAxis + yAxis,
		_center - xAxis - yAxis,
		_center + xAxis - yAxis
	};
}

void RectCollider::ProjectOntoAxis(const Vector& axis, float& min, float& max)
{
	auto corner = GetCorners();

	min = max = corner[0].Dot(axis);

	for (size_t i = 1; i < corner.size(); ++i)
	{
		float projection = corner[i].Dot(axis);
		if (projection < min) min = projection;
		if (projection > max) max = projection;
	}
}

bool RectCollider::IsCollision(const Vector& pos) const
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<class CircleCollider> other) const
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<class RectCollider> other) const
{
	return false;
}