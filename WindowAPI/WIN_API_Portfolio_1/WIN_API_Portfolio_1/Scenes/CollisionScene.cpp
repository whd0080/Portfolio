#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_fixedCircle = make_shared<CircleCollider>(Vector(400, 400), 70);
	_fixedRect = make_shared<RectCollider>(Vector(500, 200), Vector(100, 100), 0.0f);
	_movableCircle = make_shared<CircleCollider>(Vector(0, 0), 100);
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_fixedCircle->Update();
	_fixedRect->Update();
	_movableCircle->Update();

	if (_fixedCircle->IsCollision(mousePos))
		_fixedCircle->SetRed();
	else
		_fixedCircle->SetGreen();

	_movableCircle->Center() = mousePos;

	if (_fixedCircle->IsCollision(_movableCircle))
		_fixedCircle->SetRed();
	else
		_fixedCircle->SetGreen();

	if (_movableCircle->IsCollision(_fixedRect))
	{
		/*shared_ptr<RectCollider> rect = dynamic_pointer_cast<RectCollider>(_fixedRect);
		rect->Rotation(0.01f);*/

		_fixedRect->SetRed();
	}
	else
		_fixedRect->SetGreen();
}

void CollisionScene::Render(HDC hdc)
{
	_fixedCircle->Render(hdc);
	_fixedRect->Render(hdc);
	_movableCircle->Render(hdc);
}