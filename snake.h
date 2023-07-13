#pragma once

#include <iostream>
#include <vector>
#include "direction.h"

class Snake
{

private:

	std::vector<std::pair<size_t, size_t>> _parts;

	Direction _direction;

public:

	Snake() : _parts({{0,0} }), _direction(Direction::RIGHT) {}

	Snake(const Snake& other) = delete;
	Snake& operator=(const Snake& other) = delete;

	void Grow();
	void Move();

	void SetDirection(Direction direction) { _direction = direction; }
	std::pair<size_t, size_t> GetNextPart() const;

	bool CanMove() const;

	size_t GetLength() const { return _parts.size(); }

	const std::pair<size_t, size_t>& operator[](size_t index) const { return _parts[index]; }

};