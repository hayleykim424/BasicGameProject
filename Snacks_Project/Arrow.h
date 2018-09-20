#pragma once
#include <iostream>
#include<SDL.h>
#include "Vector.h"
#include "GameObject.h"
#include "KeyboardHandler.h"
#include "Globals.h"
using namespace std;

class Arrow :
	public GameObject
{
	SDL_Texture* texture = NULL;

private:
	
	int w, h;

public:
	SDL_Renderer* renderer;
	Arrow();
	~Arrow();

	Vector pos; //position
	

	void setTexture(SDL_Texture* texture);
	void setWidthAndHeight(int w, int h);

	//override GameObject methods
	virtual void update(float dt);
	virtual void draw(int x, int y);


};

