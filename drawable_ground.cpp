#include "drawable_ground.h"

DrawableGround::DrawableGround(Ground* ground) : _ground(ground), _groundField(new char* [_ground->_height + 2])
{

	auto h = _ground->_height + 2;
	auto w = _ground->_width + 2;


	for (size_t i = 0; i < h; ++i)
	{
		_groundField[i] = new char[w + 1];
		_groundField[i][w] = '\0';
	}
	for (size_t x = 1; x < w - 1; ++x)
	{

		_groundField[0][x] = '#';
		_groundField[h - 1][x] = '#';

	}

	for (size_t y = 1; y < h - 1; ++y)
	{
		_groundField[y][0] = '#';
		_groundField[y][w - 1] = '#';
	}

	_groundField[0][0] = ' ';
	_groundField[0][w - 1] = ' ';
	_groundField[h - 1][0] = ' ';
	_groundField[h - 1][w - 1] = ' ';

}


void DrawableGround::Draw() const
{
	auto h = _ground->_height + 2;
	auto w = _ground->_width + 2;

	for (size_t y = 1; y < h - 1; ++y)
	{
		for (size_t x = 1; x < w - 1; ++x)
		{
			_groundField[y][x] = ' ';
		}
	}

	const auto& snake = _ground->_snake;

	for (size_t i = 0; i < snake.GetLength(); ++i)
	{
		auto pair = snake[i];

		auto x = pair.first;
		auto y = pair.second;

		_groundField[y + 1][x + 1] = '*';

		if(i < snake.GetLength() - 1)
			_groundField[y + 1][x + 1] = '*';
		else
			_groundField[y + 1][x + 1] = '@';
	}

	auto foodPoint = _ground->_food.GetPoint();

	auto foodX = foodPoint.first;
	auto foodY = foodPoint.second;

	_groundField[foodY + 1][foodX + 1] = '$';

	system("cls");

	std::cout << "SCORE: " << _ground->GetScore() << std::endl;

	for (size_t i = 0; i < h; ++i)
		std::cout << _groundField[i] << std::endl <<std::flush;
	
}

DrawableGround::~DrawableGround()
{
	for (size_t i = 0; i < _ground->_height + 2; ++i)
		delete[] _groundField[i];

	delete[] _groundField;
}
