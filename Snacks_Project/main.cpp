#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <SDL_ttf.h>

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
	window = SDL_CreateWindow("Tutorial 1 task 2 Hayley Kim 6720", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);

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

	//Load up our font
	//								font file path				font size
	TTF_Font* font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 16);
	//create a colour for our text
	SDL_Color textcolour = { 0, 0, 255, 255 }; //RGBA
	//Create surface using font, colour and desired output text
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Hello Game!", textcolour);
	//convert suface to texture
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	//don't need the surface no more
	SDL_FreeSurface(textSurface);

	//setup rectangle to describe where to draw this text
	SDL_Rect textDestination;
	textDestination.x = 50;
	textDestination.y = 50;

	//to get the width and height, query the surface
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);























	bool loop = true;

	while (loop)
	{
		
		//backgroud colour
		SDL_SetRenderDrawColor(renderer, 255, 215, 201, 255);
		//Clearing screen with current draw colour
		SDL_RenderClear(renderer);


		SDL_RenderPresent(renderer);

		if (SDL_GetTicks() > 6500)
			loop = false;


	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	system("pause");
	return 0;
}