#include "snake_game.h"

size_t RangedRandom(size_t left, size_t right)
{
	return (rand() % (right - left + 1) + left);
}

void main()
{
	srand(time(nullptr));

	while(true)
	{
			
		SnakeGame game(RangedRandom(10, 25), RangedRandom(10, 25));
		system("pause");
	}

}
