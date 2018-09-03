#include <iostream>
#include <string>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Animation.h"
#include "GameObject.h"
#include "Arrow.h"

#include "KeyboardHandler.h"

#include <list>

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
		system("pause");
		return -1;
	}

	//Creating window
	window = SDL_CreateWindow("SNACKS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 700, SDL_WINDOW_SHOWN);

	if (window != NULL)
		cout << "Window created :)" << endl;
	else
	{
		cout << "Failed to create window :(" << endl;
		return -1;
	}

	//Creating renderer to help draw on the screen
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer != NULL)
		cout << "Renderer created :))\n";
	else
	{
		cout << "Renderer failed:((\n";
		return -1;
	}

	//Init TTF
	if (TTF_Init() != 0)
	{
		//if failed
		cout << "SDL TTF FAILED" << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}



	//Load up a surface
	SDL_Surface* arrowSurface = SDL_LoadBMP("assets/arrow3.bmp");
	//convert it to a texture
	SDL_Texture* arrowTexture = SDL_CreateTextureFromSurface(renderer, arrowSurface);
	//dont need surface anymore, clean up its memory
	SDL_FreeSurface(arrowSurface);

	//which region of the texture to copy from
	SDL_Rect arrowSourceRect;

	//region on the screen to copy source to (can be different sizes, will stretch)
	SDL_Rect arrowDestination;


	SDL_QueryTexture(arrowTexture, NULL, NULL, &arrowSourceRect.w, &arrowSourceRect.h);
	cout << "The knight is " << arrowSourceRect.w << " by " << arrowSourceRect.h << "pixels" << endl;


	arrowSourceRect.x = 40;
	arrowSourceRect.y = 40;


	arrowDestination.x = 100; //arrow position x
	arrowDestination.y = 250; //arrow position y
	arrowDestination.w = 47; //arrow width
	arrowDestination.h = 37; //arrow height



	//Build an arrow
	Arrow* arrow = new Arrow();
	arrow->renderer = renderer;
	arrow->setWidthAndHeight(47, 37);


	//Load up TEXT: SNACKS***********************************************************
	//								font file path				font size
	TTF_Font* font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 100);
	//create a colour for our text
	SDL_Color textcolour = { 0, 0, 0, 255 }; //RGBA
	//Create surface using font, colour and desired output text
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "SNACKS", textcolour);
	//convert suface to texture
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	//don't need the surface no more
	SDL_FreeSurface(textSurface);

	//setup rectangle to describe where to draw this text
	SDL_Rect textDestination;
	textDestination.x = 92;
	textDestination.y = 100;

	//to get the width and height, query the surface
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

	//TEXT: Play Game*****************************************************************
	TTF_Font* font1 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour1 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface1 = TTF_RenderText_Blended(font1, "Play Game", textcolour1);
	SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(renderer, textSurface1);
	SDL_FreeSurface(textSurface1);

	SDL_Rect textDestination1;
	textDestination1.x = 170;
	textDestination1.y = 250;

	SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);

	//TEXT: Instruction*****************************************************************
	TTF_Font* font2 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour2 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface2 = TTF_RenderText_Blended(font2, "Instruction", textcolour2);
	SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(renderer, textSurface2);
	SDL_FreeSurface(textSurface2);

	SDL_Rect textDestination2;
	textDestination2.x = 170;
	textDestination2.y = 320;

	SDL_QueryTexture(textTexture2, NULL, NULL, &textDestination2.w, &textDestination2.h);


	//TEXT: Exit*****************************************************************
	TTF_Font* font3 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour3 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface3 = TTF_RenderText_Blended(font3, "Exit", textcolour3);
	SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(renderer, textSurface3);
	SDL_FreeSurface(textSurface3);

	SDL_Rect textDestination3;
	textDestination3.x = 170;
	textDestination3.y = 390;

	SDL_QueryTexture(textTexture3, NULL, NULL, &textDestination3.w, &textDestination3.h);
	
	//LIST OF ALL GAME OBJECTS
	list<GameObject*> gameObjects;


	

	



	bool loop = true;


	while (loop)
	{
		
		//backgroud colour
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//Clearing screen with current draw colour
		SDL_RenderClear(renderer);
		
		

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			//check if user has closed window
			if (event.type == SDL_QUIT)
			{
				//exit loop
				loop = false;
			}
		}


		//SDL_RenderCopy(renderer, arrowTexture, &arrowSourceRect, &arrowDestination);
		SDL_RenderCopy(renderer, arrowTexture, &arrowSourceRect, &arrowDestination);

		//render textTexture
		SDL_RenderCopy(renderer, textTexture, NULL, &textDestination); //SNACKS
		SDL_RenderCopy(renderer, textTexture1, NULL, &textDestination1); //play game
		SDL_RenderCopy(renderer, textTexture2, NULL, &textDestination2); //Instruction
		SDL_RenderCopy(renderer, textTexture3, NULL, &textDestination3); //Exit
		
		//when done drawing, present all our renderings to the window
		SDL_RenderPresent(renderer);

	}

	//cleanup
	SDL_DestroyTexture(textTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//shut down sdl sub systems
	SDL_Quit();

	system("pause");
	return 0;
}