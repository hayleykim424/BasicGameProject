#pragma once
#include <SDL.h>
#include "GameStateMachine.h"
class Globals
{
public:
	Globals();
	~Globals();

	static SDL_Renderer *renderer;
	static bool quitGame;
	static GameStateMachine gsm;
};
