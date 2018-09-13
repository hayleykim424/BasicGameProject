#pragma once
#include <SDL.h>

#include "Hero.h"

class InputHandler
{
public:
//	Arrow *arrow;
	Hero *hero;
	InputHandler();
	~InputHandler();

	//abstract function
	virtual void update(SDL_Event* event) = 0; // <=== abstract has no body. it c++ we show this with = 0
};

