#include "Arrow.h"


Arrow::Arrow()
{
}


Arrow::~Arrow()
{
}

void Arrow::setTexture(SDL_Texture* texture)
{
	this->texture = texture;
}

void Arrow::draw()
{
	pos.x = 200;
	pos.y = 200;
}

void Arrow::setWidthAndHeight(int w, int h)
{
	this->w = w;
	this->h = h;
}