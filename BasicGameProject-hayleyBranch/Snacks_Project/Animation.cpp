#include "Animation.h"


Animation::Animation(SDL_Texture* spriteSheet, SDL_Renderer* renderer, int numberOfFrames, int frameWidth, int frameHeight, float frameDuration){
	this->spriteSheet = spriteSheet;
	this->renderer = renderer;
	this->numberOfFrames = numberOfFrames;
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	this->frameDuration = frameDuration;

	currentFrame = 0;
	frameTimer = 0;
}
void Animation::update(float dt){
	//update frameTimer
	frameTimer += dt;

	//if frameTimer lasted >= frameDuration, move to next frame
	if (frameTimer >= frameDuration){
		currentFrame++;
		//reset timer
		frameTimer = 0;

		if (currentFrame >= numberOfFrames)
		{
			//cycle back to the start of the animation
			currentFrame = 0;
		}
	}
}
void Animation::draw(int x, int y){
	SDL_Rect srcRect;
	srcRect.x = currentFrame*frameWidth;
	srcRect.y = 0;
	srcRect.w = frameWidth;
	srcRect.h = frameHeight;

	//setup destination rect
	SDL_Rect destRect = { x, y, frameWidth, frameHeight };
	//draw
	SDL_RenderCopy(renderer, spriteSheet, &srcRect, &destRect);
}

void Animation::draw(int x, int y, bool flip){
	SDL_Rect srcRect;
	srcRect.x = currentFrame*frameWidth;
	srcRect.y = 0;
	srcRect.w = frameWidth;
	srcRect.h = frameHeight;

	//setup destination rect
	SDL_Rect destRect = { x, y, frameWidth, frameHeight };

	//check if  need to flip
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	if (flip)
		flipType = SDL_FLIP_HORIZONTAL;

	//draw                                                 angle, rotationPoint, flip type
	SDL_RenderCopyEx(renderer, spriteSheet, &srcRect, &destRect, 0, 0, flipType);
}