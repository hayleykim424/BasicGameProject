#pragma once
#include "GameObject.h"
#include "Animation.h"
class Hero :
	public GameObject
{
private:
	Animation *animation = NULL;
	bool faceRight = true;

public:
	Hero();
	~Hero();

	void setAnimation(Animation *animation);

	//override GameObject methods
	virtual void update(float dt);
	virtual void draw();

	bool AABBCheck(SDL_Rect b1, SDL_Rect b2);
};

