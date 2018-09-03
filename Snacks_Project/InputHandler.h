#pragma once
#include <SDL.h>
#include "Arrow.h"

class InputHandler
{
public:
	Arrow* arrow;

	InputHandler();
	~InputHandler();

	//abstract function
	virtual void update(SDL_Event* event) = 0; // <=== abstract has no body. it c++ we show this with = 0
};

