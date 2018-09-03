#pragma once
#include <SDL.h>


class Animation
{
public:
	//basic information we need
	int numberOfFrames;
	int frameWidth, frameHeight;
	float frameDuration; //how long does frame appear on screen
	SDL_Texture* spriteSheet; //image we will be sourcing from
	SDL_Renderer* renderer; //need it for drawing

	//current state of the animation
	int currentFrame; //which frame to show (starts at 0)
	float frameTimer;//timer that ticks down by dt increments

	Animation(SDL_Texture* spriteSheet, SDL_Renderer* renderer, int numberOfFrames, int frameWidth, int frameHeight, float frameDuration);
	void update(float dt);//update timers and things
	void draw(int x, int y);
	void draw(int x, int y, bool flip);
};
