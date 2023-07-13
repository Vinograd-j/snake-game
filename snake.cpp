#include "Snake.h"

void Snake::Grow()
{
	_parts.push_back(GetNextPart());
}

void Snake::Move()
{
	for (size_t i = 0; i < _parts.size() - 1; ++i)
		_parts[i] = _parts[i + 1];
	
	_parts[_parts.size() - 1] = GetNextPart();
}

std::pair<size_t, size_t> Snake::GetNextPart() const
{

	auto head = _parts.back();

	switch (_direction)
	{

	case Direction::RIGHT:
		return { head.first + 1, head.second };

	case Direction::LEFT:
		return { head.first - 1, head.second };

	case Direction::UP:
		return { head.first, head.second - 1 };

	case Direction::DOWN:
		return { head.first, head.second + 1 };
	}
	
	throw std::logic_error("Unknown direction");
}

bool Snake::CanMove() const
{

	auto nextPart = GetNextPart();

	for (auto& _part : _parts)
		if (_part == nextPart)
			return false;

	return true;
}
