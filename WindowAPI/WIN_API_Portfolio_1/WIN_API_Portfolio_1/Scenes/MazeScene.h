#pragma once

class Block;
class Maze;

class MazeScene : public Scene
{
public:
	MazeScene();
	~MazeScene();

	void PostInitilize() override;
	void Update() override;
	void Render(HDC hdc) override;

private:
	// 25 x 25
	shared_ptr<Maze> _maze;
};