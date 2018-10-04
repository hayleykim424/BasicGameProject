#include "Globals.h"


Globals::Globals()
{
	score = 0;
}


Globals::~Globals()
{
}

SDL_Renderer* Globals::renderer = NULL;
bool Globals::quitGame = false;
GameStateMachine Globals::gsm;
int Globals::screenWidth = 450;
int Globals::screenHeight = 600;
int Globals::heroScore = 0;
