#include "ground.h"

bool Ground::TryMoveSnake()
{

	const std::lock_guard<std::mutex> lock(_lockObject);

	if (!_snake.CanMove())
		return false;

	auto nextPart = _snake.GetNextPart();

	if (nextPart.first >= _width || nextPart.second >= _height)
		return false;

	if(nextPart == _food.GetPoint())
	{
		_snake.Grow();
		if (!TrySpawnFood())
			return false;
	}else
	{
		_snake.Move();
	}

	return true;
}

void Ground::ChangeSnakeDirection(Direction direction)
{
	const std::lock_guard<std::mutex> lock(_lockObject);

	_snake.SetDirection(direction);
	
}

size_t Ground::GetScore()
{
	return _snake.GetLength();
}


bool SnakeContainsPart(const Snake& snake, size_t x, size_t y)
{

	for (size_t i = 0; i < snake.GetLength(); ++i)
	{

		const auto& part = snake[i];

		if (part.first == x && part.second == y)
			return true;
	}

	return false;
}

bool Ground::TrySpawnFood()
{
	std::vector<size_t> freeRows(_height / 2);

	for (size_t y = 0; y < _height; ++y)
	{
		for (size_t x = 0; x < _width; ++x)
		{
			if (!SnakeContainsPart(_snake, x, y))
			{
				freeRows.push_back(y);
				break;
			}
		}
	}

	if (freeRows.empty())
		return false;

	auto randomRowIndex = rand() % freeRows.size();

	size_t y = freeRows[randomRowIndex];

	std::vector<size_t> freeColumns(_width / 2);
	
	for (size_t x = 0; x < _width; ++x)
	{
		if (!SnakeContainsPart(_snake, x, y))
		{
			freeColumns.push_back(x);
		}
	}

	auto randomColumnIndex = rand() % freeColumns.size();

	size_t x = freeColumns[randomColumnIndex];

	_food = Food(x, y);

	return true;
}

