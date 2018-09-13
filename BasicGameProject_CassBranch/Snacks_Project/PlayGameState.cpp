#include "PlayGameState.h"


PlayGameState::PlayGameState()
{
	SDL_Surface *runSurface = IMG_Load("assets/run.png");
	//make the background color of this image transparent
	SDL_SetColorKey(runSurface, 1, SDL_MapRGB(runSurface->format, 120, 120, 255));
	//convert to texture
	heroTexture = SDL_CreateTextureFromSurface(Globals::renderer, runSurface);

	SDL_FreeSurface(runSurface);

	heroAnimation = new Animation(heroTexture, Globals::renderer, 4, 32, 32, 0.9);

	hero = new Hero();
	hero->setAnimation(heroAnimation);
	hero->setRenderer(Globals::renderer);
	hero->pos.x = 200;
	hero->pos.y = 200;

	/*
	ball1 = new Ball();
	ball1->setRenderer(Globals::renderer);
	ball1->pos.x = 100;
	ball1->pos.y = 0;

	ball2 = new Ball();
	ball2->setRenderer(Globals::renderer);
	ball2->pos.x = 400;
	ball2->pos.y = 0;
	*/
	//add them to the list of game objects
	gameObjects.push_back(hero);
	//gameObjects.push_back(ball1);
	//gameObjects.push_back(ball2);

	keyboardHandler.hero = hero;
	mouseHandler.hero = hero;
	controllerHandler.hero = hero;

	lastUpdate = SDL_GetTicks();



}


PlayGameState::~PlayGameState()
{
	//cleanup dynamic memory
	delete hero;
	//delete ball1;
	//delete ball2;
	delete heroAnimation;
	SDL_DestroyTexture(heroTexture);

}

void PlayGameState::update()
{
	//update time management stuff
	Uint32 timeStuff = SDL_GetTicks() - lastUpdate;
	dt = timeStuff / 1000.0;
	lastUpdate = SDL_GetTicks();

	//deal with events
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		//check if user has closed window
		if (event.type == SDL_QUIT)
		{
			//exit loop
			Globals::quitGame = true;
		}
		//chech id keyboard button pressed
		if (event.type == SDL_KEYDOWN)
		{
			//check if ESC key is pressed
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				//exit loop
				//Globals::quitGame = true;
				Globals::gsm.pushState(new MenuGameState());
				
			}
			//space bar for effect sound
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && event.key.repeat == 0)
			{
				//SoundManager::soundManager.playSound("explode");
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_S && event.key.repeat == 0)
			{
				//SoundManager::soundManager.playSound("jump");
			}
		}
		//pass this event into our hero input handlers
		if (controllerHandler.controller != NULL)
			controllerHandler.update(&event);
		else
			keyboardHandler.update(&event);


		mouseHandler.update(&event);
	}

	for each (GameObject *go in gameObjects)
	{
		go->update(dt);

	}

}

void PlayGameState::render()
{
	SDL_SetRenderDrawColor(Globals::renderer, 255, 90, 0, 255);
	SDL_RenderClear(Globals::renderer);
	for each (GameObject *go in gameObjects)
	{
		go->draw();
	}


	SDL_RenderPresent(Globals::renderer);
}

bool PlayGameState::onEnter()
{
	cout << "Enter Play Game State" << endl;
	return true;

}

bool PlayGameState::onExit()
{
	cout << "Exit Play Game State" << endl;
	return true;

}