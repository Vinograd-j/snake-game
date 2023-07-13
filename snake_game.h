#pragma once

#include "drawable_ground.h"
#include "ground.h"
#include "move_controller.h"


class SnakeGame
{

private:

	Ground _ground;

	DrawableGround _drawableGround;

	MoveController _moveController;

	size_t _speed;

public:

	SnakeGame(size_t height, size_t width);

	SnakeGame(const SnakeGame& other) = delete;
	SnakeGame& operator=(const SnakeGame& other) = delete;

private:

	void StartGame();

};


