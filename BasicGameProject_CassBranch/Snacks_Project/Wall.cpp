#include "Wall.h"


Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::setWidthAndHeight(int w, int h){
	this->w = w;
	this->h = h;
}

void Wall::draw(){
		SDL_Rect wallRect = { pos.x, pos.y, w, h };

	//								 R	 G	 B	  A
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &wallRect);

}