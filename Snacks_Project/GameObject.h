#pragma once
#include <SDL.h>
#include "Vector.h"
#include <string>

using namespace std;

class GameObject{
protected:
	SDL_Renderer* renderer;

public:
	Vector pos; //position
	Vector velocity; //how fast to move in any direction
	bool removeObj = false;
	string type = "gameobject";

	void setRenderer(SDL_Renderer* renderer);


	virtual void update(float dt);
	virtual void updateMovement(float dt);
	virtual void draw();

};