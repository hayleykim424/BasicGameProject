#pragma once
#include "GameState.h"
#include <list>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Hero.h"
#include "Wall.h"
#include "KeyboardHandler.h"
#include "GameControllerHandler.h"
#include "MouseHandler.h"
#include "Globals.h"
#include "MenuGameState.h"
#include "FallingObject.h"

class PlayGameState :
	public GameState
{
public:
	SDL_Texture *heroTexture;
	Animation *heroAnimation;

	SDL_Texture *fruitTexture;
	Animation *fruitAnimation;

	Hero *hero;
	Wall *wallTop;
	Wall *wallLeft;
	Wall *wallRight;
	Wall *wallBottom;
	FallingObject *fallingObj;
	
	SDL_Texture *textTexture;
	SDL_Texture* textTexture1 = NULL;
	SDL_Texture* textTexture2 = NULL;

	SDL_Rect textDestination1;
	SDL_Rect textDestination2;

	float nextDropTimer = 1; //1 = 1 second, so 0.100 = 100ms

	list<GameObject*> gameObjects;

	KeyboardHandler keyboardHandler;
	MouseHandler mouseHandler;
	GameControllerHandler controllerHandler;

	Uint32 lastUpdate;//last sdl_getTicks();
	float dt = 0;


	PlayGameState();
	~PlayGameState();

	//override those abstract methods inherited
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID(){
		return "playState";
	}
};