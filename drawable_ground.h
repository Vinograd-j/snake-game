#pragma once

#include "ground.h"

class DrawableGround
{

private:

	Ground* _ground;

	char** _groundField;

public:

	explicit DrawableGround(Ground* ground);

	void Draw() const;

	DrawableGround(const DrawableGround& other) = delete;
	DrawableGround& operator=(const DrawableGround& other) = delete;

	~DrawableGround();

};
