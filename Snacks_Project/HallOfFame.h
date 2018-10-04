#pragma once
#include "GameState.h"
#include "Globals.h"
#include <fstream>
#include <SDL_ttf.h>

#include "PlayGameState.h"
#include <list>
#include <SDL_image.h>
#include "Hero.h"
#include "Wall.h"
#include "KeyboardHandler.h"
#include "GameControllerHandler.h"
#include "MouseHandler.h"
#include "MenuGameState.h"
#include "FallingObject.h"

class HallOfFame :
	public GameState
{
public:
	HallOfFame();
	~HallOfFame();

	SDL_Texture* textTexture = NULL;
	SDL_Texture* textTexture1 = NULL;
	SDL_Texture* textTexture2 = NULL;
	SDL_Texture* textTexture3 = NULL;
	SDL_Rect textDestination;
	SDL_Rect textDestination1;
	SDL_Rect textDestination2;
	SDL_Rect textDestination3;

	TTF_Font* font1;

	SDL_Color textcolour1;
	SDL_Surface* textSurface1;

	//override those abstract methods inherited
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID(){
		return "hallOfFameState";
	}
};
