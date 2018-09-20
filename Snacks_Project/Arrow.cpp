#include "Arrow.h"


Arrow::Arrow()
{
	/*
	//Load up a ARROW IMAGE
	SDL_Surface* arrowSurface = SDL_LoadBMP("assets/arrow3.bmp");
	//make the background color of this image transparent
	SDL_SetColorKey(arrowSurface, 1, SDL_MapRGB(arrowSurface->format, 255, 255, 255));
	//convert it to a texture
	SDL_Texture* arrowTexture = SDL_CreateTextureFromSurface(Globals::renderer, arrowSurface);
	//dont need surface anymore, clean up its memory
	SDL_FreeSurface(arrowSurface);
	//which region of the texture to copy from
	SDL_Rect arrowSourceRect = { 0, 0, 40, 40 };

	//region on the screen to copy source to (can be different sizes, will stretch)
	SDL_Rect arrowDestination = { 10, 25 };


	SDL_QueryTexture(arrowTexture, NULL, NULL, &arrowDestination.w, &arrowDestination.h);
	*/
}


Arrow::~Arrow()
{
}


void Arrow::update(float dt)
{
	
}
void Arrow::draw(int x, int y)
{
	
	
}

void Arrow::setTexture(SDL_Texture* texture)
{
	this->texture = texture;
}



void Arrow::setWidthAndHeight(int w, int h)
{
	this->w = w;
	this->h = h;
}
