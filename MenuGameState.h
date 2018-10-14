#pragma once
#include "GameState.h"
#include "Globals.h"
#include "PlayGameState.h"
#include "HallOfFame.h"
#include <SDL_ttf.h>
class MenuGameState :
	public GameState
{
public:
	MenuGameState();
	~MenuGameState();

	SDL_Texture* textTexture = NULL;
	SDL_Texture* textTexture1 = NULL;
	SDL_Texture* textTexture2 = NULL;
	SDL_Texture* textTexture3 = NULL;
	SDL_Texture* textTextureInstr = NULL;

	SDL_Rect textDestination;
	SDL_Rect textDestination1;
	SDL_Rect textDestination2;
	SDL_Rect textDestination3;
	SDL_Rect textDestinationInstr;

	//override those abstract methods inherited
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID(){
		return "menuState";
	}

};

