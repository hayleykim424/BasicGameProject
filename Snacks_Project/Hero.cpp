#include "Hero.h"


Hero::Hero()
{
	type = "hero";
}


Hero::~Hero()
{
}

void Hero::setAnimation(Animation *animation){
	this->animation = animation;
	level = 1;
	score = 0;
	hp = 2;
}

int Hero::calculateScoreAndLevel(int heroScore)
{
	score = score + heroScore;

	if (score > 2000)
	{
		level = 2;
	}
	cout << "Score: " << score << endl;
	cout << "Level: " << level << endl;
	return score;
	
}

int Hero::getHeroLevel()
{
	return level;
}

int Hero::getHeroHp()
{
	return hp;
}

int Hero::getHeroScore()
{
	return score;
}


void Hero::takeHpOff(int heroHp)
{
	hp -= heroHp;
}


void Hero::update(float dt)
{
	//if moving on the X axis, change facing
	if (velocity.x > 0)
		faceRight = true;
	else if (velocity.x < 0)
		faceRight = false;

	//stop the hero at the end of left wall
	if (pos.x < -15){
		pos.x = -15;
	}

	//stop the hero at the end of right wall
	if (pos.x > 402){
		pos.x = 402;
	}


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

bool Hero::AABBCheck(SDL_Rect b1, SDL_Rect b2)
{
	return !(b1.x + b1.w < b2.x || b1.x > b2.x + b2.w || b1.y + b1.h < b2.y || b1.y > b2.y + b2.h);
}