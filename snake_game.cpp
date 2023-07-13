#include "snake_game.h"

#include <thread>
#include <windows.h>
#include <iostream>
#include <string>

std::atomic<bool> isGameInProcess(false);


size_t TryParseSizeTOrElse(const std::string& string, size_t defaultValue)
{

	size_t number = 0;

	for (auto iterator = string.begin(); iterator != string.end(); ++iterator)
	{

		char c = *iterator;

		if (c < '0' || c > '9')
			return defaultValue;

		number += c - '0';
		number *= 10;
	}
	
	return number / 10;
}

size_t InputSpeed()
{
	std::string inputText;

	while(true)
	{
		std::cout << "Enter a speed: ";
		std::getline(std::cin, inputText);

		if (inputText.empty())
			return 5;

		size_t inputSpeed = TryParseSizeTOrElse(inputText, 0);

		if (inputSpeed == 0)
		{
			std::cout << "The input speed is invalid. Speed must be positive. Try again" << std::endl;
			continue;
		}

		return inputSpeed;
	}
	
}

SnakeGame::SnakeGame(size_t height, size_t width): _ground(height, width), _drawableGround(&_ground), _moveController(&_ground), _speed(InputSpeed())
{
	StartGame();
}

void SnakeGame::StartGame()
{

	std::thread gameLogicThread([this]
	{
		isGameInProcess = true;

		std::thread moveControllingThread([this]
		{
			_moveController.Listen(isGameInProcess);
		});

		while (true)
		{
			bool snakeCanMove = _ground.TryMoveSnake();

			if (!snakeCanMove)
			{
				isGameInProcess = false;
				break;
			}

			_drawableGround.Draw();

			Sleep(1000 / _speed);
		}

		moveControllingThread.join();

	});

	gameLogicThread.join();
}
