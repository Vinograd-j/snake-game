#pragma once

#include "ground.h"


class MoveController
{

private:

	Ground* _ground;

public:

	explicit MoveController(Ground* ground) : _ground(ground) {}

	void Listen(const std::atomic<bool>& isGameInProcess) const;

	MoveController(const MoveController& other) = delete;
	MoveController& operator=(const MoveController& other) = delete;

};

