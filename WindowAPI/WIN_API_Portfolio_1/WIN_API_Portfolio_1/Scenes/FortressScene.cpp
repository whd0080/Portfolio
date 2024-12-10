#include "framework.h"
#include "FortressScene.h"

#include "Contents/GameObject/Cannon.h"

FortressScene::FortressScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

	_cannon2->SetCenter(Vector(1100, 350));

	_cannon1->SetTurn(true);
	_cannon2->SetTurn(false);
}

FortressScene::~FortressScene()
{
}

void FortressScene::PostInitilize()
{
	_cannon1->PostInitilize();
	_cannon2->PostInitilize();
}

void FortressScene::Update()
{
	if (_cannon1->GetHit(_cannon2->GetBall()))
	{
		_cannon1->GetCircle()->SetRed();
	}
	else
	{
		_cannon1->GetCircle()->SetGreen();
	}

	if (_cannon2->GetHit(_cannon1->GetBall()))
	{
		_cannon2->GetCircle()->SetRed();
	}
	else
	{
		_cannon2->GetCircle()->SetGreen();
	}

	_cannon1->MyTurn(_cannon2);
	_cannon1->Update();
	_cannon2->MyTurn(_cannon1);
	_cannon2->Update();
	
}

void FortressScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}