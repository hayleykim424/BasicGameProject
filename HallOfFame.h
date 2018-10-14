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

<<<<<<< HEAD
	SDL_Texture* textTexture00 = NULL;
	SDL_Texture* textTexture11 = NULL;
	SDL_Texture* textTexture22 = NULL;
	SDL_Texture* textTexture33 = NULL;
	SDL_Texture* textTexture44 = NULL;
	SDL_Texture* textTexture55 = NULL;
	SDL_Texture* textTexture66 = NULL;

	SDL_Rect textDestination00;
	SDL_Rect textDestination11;
	SDL_Rect textDestination22;
	SDL_Rect textDestination33;
	SDL_Rect textDestination44;
	SDL_Rect textDestination55;
	SDL_Rect textDestination66;

	TTF_Font* font11;
	TTF_Font* font66;

	SDL_Color textcolour11;
	SDL_Surface* textSurface11;
	SDL_Color textcolour66;
	SDL_Surface* textSurface66;
=======
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
>>>>>>> 028c64060f9cb77c3c7ad1460b06bfd87328dd35

	//override those abstract methods inherited
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID(){
		return "hallOfFameState";
	}
};
