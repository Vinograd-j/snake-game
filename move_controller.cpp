#include "move_controller.h"
#include "windows.h"

void MoveController::Listen(const std::atomic<bool>& isGameInProcess) const
{
	while (isGameInProcess)
	{
		if (GetKeyState(VK_UP) & 0X8000)
			_ground->ChangeSnakeDirection(Direction::UP);

		else if (GetKeyState(VK_DOWN) & 0X8000)
			_ground->ChangeSnakeDirection(Direction::DOWN);

		else if (GetKeyState(VK_RIGHT) & 0X8000)
			_ground->ChangeSnakeDirection(Direction::RIGHT);

		else if (GetKeyState(VK_LEFT) & 0X8000)
			_ground->ChangeSnakeDirection(Direction::LEFT);
	}
}
