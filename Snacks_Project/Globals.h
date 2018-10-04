#pragma once
#include <SDL.h>
#include "GameStateMachine.h"
class Globals
{
private:
	int score;
public:
	Globals();
	~Globals();

	static SDL_Renderer *renderer;
	static bool quitGame;
	static GameStateMachine gsm;
	static int screenWidth, screenHeight;
	static int heroScore;
};
