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

	//override those abstract methods inherited
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID(){
		return "menuState";
	}

};

