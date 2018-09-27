#include "Globals.h"


Globals::Globals()
{
}


Globals::~Globals()
{
}

SDL_Renderer* Globals::renderer = NULL;
bool Globals::quitGame = false;
GameStateMachine Globals::gsm;
int Globals::screenWidth = 450;
int Globals::screenHeight = 600;