#pragma once
#include "GameState.h"
#include "Globals.h"
#include <SDL_ttf.h>
#include "HallOfFame.h"
#include <list>
#include <SDL_image.h>
#include "Hero.h"
#include "Wall.h"
#include "KeyboardHandler.h"
#include "GameControllerHandler.h"
#include "MouseHandler.h"
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

	SDL_Texture *angryTexture;
	Animation *angryAnimation;

	SDL_Texture *heartTexture;
	Animation *heartAnimation;

	SDL_Texture *heartTexture1;
	Animation *heartAnimation1;

	Hero *hero;
	Wall *wallTop;
	Wall *wallLeft;
	Wall *wallRight;
	Wall *wallBottom;
	FallingObject *fallingObj;
	FallingObject *fallingObjAngry;
	
	SDL_Texture *textTexture;
	SDL_Texture* textTexture1 = NULL;
	SDL_Texture* textTexture2 = NULL;
	SDL_Texture* textTexture3 = NULL;
	SDL_Texture* textTextureLife = NULL;
	SDL_Texture* textTextureScore = NULL;
	SDL_Texture* textTextureScorePoint = NULL;

	SDL_Rect textDestination1;
	SDL_Rect textDestination2;
	SDL_Rect textDestination3;
	SDL_Rect textDestinationLife;
	SDL_Rect textDestinationScorePoint;
	SDL_Rect heartDestination;
	SDL_Rect heartDestination1;
	SDL_Rect scoreDestination; //number

	TTF_Font* fontScore;

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