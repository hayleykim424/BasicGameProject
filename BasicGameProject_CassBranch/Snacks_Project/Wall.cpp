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
		

	//								 R	 G	 B	  A
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect wallRect = { pos.x-25, pos.y-25, w, h };
	SDL_RenderFillRect(renderer, &wallRect);

}