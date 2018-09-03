#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler()
{
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event* event)
{
	//Check if key is held down (Uint8: unsigned short int)
	const Uint8* keystates = SDL_GetKeyboardState(NULL); //pass in array of keys you want to check OR NULL if you want state of all keys


	//key is considered down if = 1, no held down = 0
	//if (keystates[SDL_SCANCODE_UP])
		//arrow->velocity.y = -170;
	//if (keystates[SDL_SCANCODE_DOWN])
		//arrow->velocity.y = 170;

}