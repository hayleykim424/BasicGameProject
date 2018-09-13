#include "Hero.h"


Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::setAnimation(Animation *animation){
	this->animation = animation;

}



void Hero::update(float dt)
{
	//if moving on the X axis, change facing
	if (velocity.x > 0)
		faceRight = true;
	else if (velocity.x < 0)
		faceRight = false;

	//move character based on velocity	
	updateMovement(dt);

	//update character animation
	animation->update(dt);

}


void Hero::draw(){
	if (animation != NULL)
	{
		if (faceRight)
			animation->draw(pos.x, pos.y);
		else
			animation->draw(pos.x, pos.y, true);//flip image to face left
	}

}