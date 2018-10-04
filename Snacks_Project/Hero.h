#pragma once
#include <iostream>
#include <string>
#include "GameObject.h"
#include "Animation.h"

using namespace std;

class Hero :
	public GameObject
{
private:
	Animation *animation = NULL;
	bool faceRight = true;
	int level, score, hp;

public:
	Hero();
	~Hero();

	
	void setAnimation(Animation *animation);

	void takeHpOff(int);
	int calculateScoreAndLevel(int heroScore);

	int getHeroLevel();
	int getHeroHp();
	int getHeroScore();

	//override GameObject methods
	virtual void update(float dt);
	virtual void draw();

	bool AABBCheck(SDL_Rect b1, SDL_Rect b2);
};

