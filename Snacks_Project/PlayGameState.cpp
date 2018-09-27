#include "PlayGameState.h"


PlayGameState::PlayGameState()
{
	SDL_Surface *runSurface = IMG_Load("assets/run.png");
	SDL_Surface *fruitSurface = IMG_Load("assets/fruit.png");

	//make the background color of this image transparent
	SDL_SetColorKey(runSurface, 1, SDL_MapRGB(runSurface->format, 120, 120, 255));

	//convert to texture
	heroTexture = SDL_CreateTextureFromSurface(Globals::renderer, runSurface);
	SDL_FreeSurface(runSurface);

	fruitTexture = SDL_CreateTextureFromSurface(Globals::renderer, fruitSurface);
	SDL_FreeSurface(fruitSurface);

	heroAnimation = new Animation(heroTexture, Globals::renderer, 6, 64, 70, 0.3);

	fruitAnimation = new Animation(fruitTexture, Globals::renderer, 32, 32);

	hero = new Hero();
	hero->setAnimation(heroAnimation);
	hero->setRenderer(Globals::renderer);
	hero->pos.x = 180;
	hero->pos.y = 530;

	//falling objects
	fallingObj = new FallingObject();
	fallingObj->setAnimation(fruitAnimation);
	fallingObj->pos.x = 100;
	fallingObj->pos.y = 0;

	//add them to the list of game objects
	gameObjects.push_back(hero);
	gameObjects.push_back(fallingObj);

	keyboardHandler.hero = hero;
	mouseHandler.hero = hero;
	controllerHandler.hero = hero;

	lastUpdate = SDL_GetTicks();

	//TEXT: ESC - EXIT*****************************************************************
	TTF_Font* font1 = TTF_OpenFont("assets/BebasNeueBold.ttf", 15);
	SDL_Color textcolour1 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface1 = TTF_RenderText_Blended(font1, "ESC - EXIT", textcolour1);
	textTexture1 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface1);
	SDL_FreeSurface(textSurface1);

	textDestination1;
	textDestination1.x = 380;
	textDestination1.y = 350;

	SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);


	//TEXT: Lvl 1*****************************************************************
	TTF_Font* font2 = TTF_OpenFont("assets/BebasNeueBold.ttf", 30);
	SDL_Color textcolour2 = { 128, 0, 32, 255 };
	SDL_Surface* textSurface2 = TTF_RenderText_Blended(font2, "Lv. 1", textcolour2);
	textTexture2 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface2);
	SDL_FreeSurface(textSurface1);

	textDestination2;
	textDestination2.x = 30;
	textDestination2.y = 30;

	SDL_QueryTexture(textTexture2, NULL, NULL, &textDestination2.w, &textDestination2.h);

}


PlayGameState::~PlayGameState()
{
	//cleanup dynamic memory
	delete hero;
	delete heroAnimation;
	//delete fallingObj;
	SDL_DestroyTexture(heroTexture);
	SDL_DestroyTexture(textTexture1);
	SDL_DestroyTexture(textTexture2);
}

void PlayGameState::update()
{
	//update time management stuff
	Uint32 timeStuff = SDL_GetTicks() - lastUpdate;
	dt = timeStuff / 1000.0;
	lastUpdate = SDL_GetTicks();

	//tick timer down slowly over time
	nextDropTimer -= dt;

	if (nextDropTimer <= 0){
		//timer finished, do something, then reset timer

		//falling objects
		fallingObj = new FallingObject();
		fallingObj->setAnimation(fruitAnimation);
		fallingObj->pos.x = (rand() % 380) + 20;
		fallingObj->pos.y = 0;

		gameObjects.push_back(fallingObj);

		nextDropTimer = (rand() % 1000) / 1000.0f; //0-1 e.g 0.344 = 344ms
	}

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


		if (go->type == "fallingObject"){
			//cast gameObject pointer to FallingObject pointer
			FallingObject* fo = (FallingObject*)go;

			//collision check for hero and falling obj
			SDL_Rect hero_rect = { hero->pos.x, hero->pos.y, 64, 70 };
			SDL_Rect ball_rect = { fo->pos.x, fo->pos.y, 32, 32 };


			if (hero->AABBCheck(hero_rect, ball_rect) == true)
			{
				//delete (*go);
				//go = gameObjects.erase(go);
				fo->removeObj = true;
			}
		}
		
	}

	//remove objects if needed
	for (list<GameObject*>::iterator go = gameObjects.begin(); go != gameObjects.end();/*if deleting, dont put in go++, else, go++*/ )
	{
		//* can dereference a pointer to get thing it points at
		//so (*go) gives me the GameObject* at the position in the list iterator is pointing at
		if ((*go)->removeObj)
		{
			//delete dynamic memory of game object
			delete (*go);
			//remove game object pointer from the list
			go = gameObjects.erase(go);
		}
		else
			go++;

	}

}

void PlayGameState::render()
{
	SDL_SetRenderDrawColor(Globals::renderer, 255, 255, 255, 255);
	SDL_RenderClear(Globals::renderer);

	//text
	SDL_RenderCopy(Globals::renderer, textTexture1, NULL, &textDestination1);
	SDL_RenderCopy(Globals::renderer, textTexture2, NULL, &textDestination2);

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