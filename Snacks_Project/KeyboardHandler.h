#pragma once
#include "InputHandler.h"
class KeyboardHandler :
	public InputHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();

	void update(SDL_Event* event);
};

