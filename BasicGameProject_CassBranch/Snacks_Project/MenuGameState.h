#pragma once
#include "GameState.h"
#include "Globals.h"
#include "PlayGameState.h"
#include <SDL_ttf.h>
class MenuGameState :
	public GameState
{
public:
	MenuGameState();
	~MenuGameState();

	SDL_Texture* textTexture = NULL;
	SDL_Texture* textTexture1 = NULL;
	SDL_Texture* textTexture3 = NULL;
	SDL_Rect textDestination;
	SDL_Rect textDestination1;
	SDL_Rect textDestination3;

	//override those abstract methods inherited
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID(){
		return "menuState";
	}

};

