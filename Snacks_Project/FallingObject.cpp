#include "FallingObject.h"
#include "Hero.h"

FallingObject::FallingObject()
{
	velocity.x = 0;
	velocity.y = 0;
	gravity = 300;//adding 200 velocity over 1 second

	type = "fallingObject";
}

void FallingObject::angryFallingObject()
{
	velocity.x = 0;
	velocity.y = 0;
	gravity = 200;//adding 200 velocity over 1 second

	type = "angryFallingObject";
}


FallingObject::~FallingObject()
{
}

void FallingObject::update(float dt){

	if (pos.y < 650){
		//if in air, fall
		velocity.y += gravity*dt;
	}
	else
	{
	//if on ground, stop
	//pos.y = 480;
	//velocity.y = 0;

	//if on ground, disappear
	if (velocity.y > 250)
		removeObj = true;
	else
		velocity.y = 0;

	
}

	//bouncing off the walls
	//  left wall and moving left      OR    right wall and moving right
	//if ((pos.x <= 0 && velocity.x <= 0) || (pos.x >= 640 && velocity.x >= 0))
	//{
	//	velocity.x = -velocity.x;
	//}


	updateMovement(dt);
}
void FallingObject::draw(){
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_Rect ballRect = { pos.x - 25, pos.y - 25, 50, 50 };
	//SDL_RenderFillRect(renderer, &ballRect);
	animation->draw(pos.x, pos.y);
}



void FallingObject::setAnimation(Animation *animation){
	this->animation = animation;

}

int FallingObject::getGravity(int moreGravity)
{
	gravity = gravity + moreGravity;
	return gravity;
}