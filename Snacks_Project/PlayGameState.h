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

class PlayGameState :
	public GameState
{
public:
	SDL_Texture *heroTexture;
	Animation *heroAnimation;
	Hero *hero;
	Wall *wallTop;
	
	SDL_Texture *textTexture;

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