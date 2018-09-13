#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Animation.h"
#include "GameObject.h"
#include "Arrow.h"
#include "Hero.h"

#include <conio.h>
#include <windows.h>
#include <cstdlib>

#include <list>
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "GameControllerHandler.h"
#include "SoundManager.h"
#include "Globals.h"
#include "MenuGameState.h"



using namespace std;


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//Texture pointer
SDL_Texture* texture;
SDL_Rect sourceRect;
SDL_Rect destinationRect;


int main(int argc, char **argv)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL fail initialised\n";
		return -1; //does not run the rest of the main code.
	}
	else
		cout << "SDL initialised success\n";

	//INIT SDL_image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		cout << "SDL image did not load: " << IMG_GetError() << endl;
		SDL_Quit();
		return -1;
	}

	//Creating window
	SDL_Window *window = SDL_CreateWindow("SNACKS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 700, SDL_WINDOW_SHOWN);

	if (window != NULL)
		cout << "Window created :)" << endl;
	else
	{
		cout << "Failed to create window :(" << endl;
		return -1;
	}

	//Init TTF
	if (TTF_Init() != 0)
	{
		//if failed
		cout << "SDL TTF FAILED!" << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}

	//INIT MIXER
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		cout << "Mixer didn't initialise" << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//Creating RENDERER
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer != NULL)
		cout << "Renderer created :))\n";
	else
	{
		cout << "Renderer failed:((\n";
		return -1;
	}

	//make global renderer point to te renderer we just built
	Globals::renderer = renderer;

	//LOAD UP MUSIC FILE
	Mix_Music *music = Mix_LoadMUS("assets/music.ogg");
	if (music == NULL)
	{
		cout << "MUSIC failed to load!!" << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//play song
	//params: music, how many times to play the song (-1 means infinite times)
	Mix_PlayMusic(music, -1);

	//load effect.wav, store in manager under name "explode"
	SoundManager::soundManager.loadSound("explode", "assets/effect.wav");
	SoundManager::soundManager.loadSound("jump", "assets/jump.wav");


	//start on menu screen
	Globals::gsm.pushState(new MenuGameState());

	

	
	

	
	int menu_item = 0, x = 7;
	

	//LIST OF ALL GAME OBJECTS
	list<GameObject*> gameObjects;

	
	
	
	


//WHERE THE MAGIC HAPPENS
	bool loop = true;
	while (loop)
	{
		Globals::gsm.update();
		Globals::gsm.render();

		if (Globals::quitGame || Globals::gsm.gameStates.empty())
			loop = false;
	}

	//cleanup any extra screen states
	Globals::gsm.clearAll();

	//Stop music from playing
	Mix_PauseMusic();
	//delete song from memory
	Mix_FreeMusic(music); //make sure this bit of music is not playing


	//cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//shut down sdl sub systems
	SDL_Quit();

	system("pause");
	return 0;
}
