#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler()
{
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event * event)
{
	//events can be button presses, mouse clicks, moving a stick on a game pad, etc
	//so we check which type it is
	if (event->type == SDL_KEYDOWN)//Keydown is when you press down on the key, but also when it fires repeat input from holding that key down
	{

		//lets chech if the R key is pressed and not held down repeated
		if (event->key.keysym.scancode == SDL_SCANCODE_R && event->key.repeat == 0)
		{
			//reset hero position
			hero->pos.x = 200;
			hero->pos.y = 200;
		}
		/*if (event->key.keysym.scancode == SDL_SCANCODE_DOWN && event->key.repeat == 0)
		{
			//reset hero position
			arrow->pos.x += 200;
			arrow->pos.y += 200;
		}*/

	}

	//check if key is held down
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);//pass in array of keys you want to check or NULL if you want state of all keys
	//reset velocity to zero, THEN check to see if each part should be changed
	hero->velocity.x = 0;
	hero->velocity.y = 0;

	//key is considered down if = 1, no held down = 0
	//if (keystates[SDL_SCANCODE_UP])
	//	hero->velocity.y = -80;
	//if (keystates[SDL_SCANCODE_DOWN])
	//	hero->velocity.y = 80;
	if (keystates[SDL_SCANCODE_LEFT])
		hero->velocity.x = -80;
	if (keystates[SDL_SCANCODE_RIGHT])
		hero->velocity.x = 80;

}