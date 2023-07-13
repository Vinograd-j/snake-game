#pragma once

#include <iostream>

class Food
{

private:

	std::pair<size_t, size_t> _point;

public:

	Food(size_t x, size_t y) : _point(std::pair<size_t, size_t>(x, y)) {}

	Food(const Food& other) = default;
	Food& operator=(const Food& other) = default;


	std::pair<size_t, size_t> GetPoint() const { return _point; }

};
