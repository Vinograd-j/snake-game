#pragma once
#include <mutex>

#include "direction.h"
#include "food.h"
#include "snake.h"


class Ground
{

private:

	friend class DrawableGround;

	size_t _height;
	size_t _width;

	Snake _snake;
	Food _food;

	std::mutex _lockObject;

public:

	Ground(size_t height, size_t width) : _height(height), _width(width), _food(0, 0)
	{
		TrySpawnFood();
		srand(time(nullptr));
	}

	Ground(const Ground& other) = delete;
	Ground& operator=(const Ground& other) = delete;


	bool TryMoveSnake();

	bool TrySpawnFood(); 

	void ChangeSnakeDirection(Direction direction);

	size_t GetScore();
};

