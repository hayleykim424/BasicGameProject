#pragma once
#include<SDL.h>
#include "Vector.h"
class Arrow 
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
	virtual void draw();


};

