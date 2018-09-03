#include "GameObject.h"

void GameObject::setRenderer(SDL_Renderer* renderer){
	this->renderer = renderer;
}



void GameObject::update(float dt)
{
}

void GameObject::updateMovement(float dt)
{
	pos.x += (velocity.x * dt);
	pos.y += (velocity.y * dt);
}

void GameObject::draw()
{
}

