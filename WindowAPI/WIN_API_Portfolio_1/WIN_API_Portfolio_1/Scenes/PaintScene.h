#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	int _curColor = 0;

	vector<HPEN> _pens;
	vector<HBRUSH> _brushes;

	shared_ptr<CircleCollider> myCircle = make_shared<CircleCollider>(Vector(200, 200), 70);
	shared_ptr<RectCollider> rect = make_shared<RectCollider>(Vector(400, 400), Vector(140, 70), 0.0f);
	shared_ptr<Line> line = make_shared<Line>(Vector(200, 200), Vector(400, 400));
};