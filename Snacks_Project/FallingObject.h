#pragma once
#include "GameObject.h"
#include "Animation.h"
class FallingObject :
	public GameObject
{
private:
	Animation *animation = NULL;

public:

	float gravity;

	FallingObject();
	~FallingObject();

	void update(float dt);
	void draw();
	void setAnimation(Animation *animation);
};

