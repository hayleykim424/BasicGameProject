#include "MenuGameState.h"
#include "Arrow.h"


MenuGameState::MenuGameState()
{
	//Load up TEXT: SNACKS***********************************************************
	//								font file path				font size
	TTF_Font *font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 120);
	//create a colour for our text
	SDL_Color textcolour = { 0, 0, 0, 255 }; //RGBA
	//Create surface using font, colour and desired output text
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "SNACKS", textcolour);
	//convert suface to texture
	textTexture = SDL_CreateTextureFromSurface(Globals::renderer, textSurface);
	//don't need the surface no more
	SDL_FreeSurface(textSurface);

	//setup rectangle to describe where to draw this text
	 textDestination;
	textDestination.x = 26;
	textDestination.y = 100;
	//to get the width and height, query the surface
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);


	//TEXT: Play Game*****************************************************************
	TTF_Font* font1 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour1 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface1 = TTF_RenderText_Blended(font1, "Press Enter to Play", textcolour1);
	 textTexture1 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface1);
	SDL_FreeSurface(textSurface1);

	 textDestination1;
	textDestination1.x = 80;
	textDestination1.y = 270;

	SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);


	//TEXT: WELCOME*****************************************************************

	TTF_Font* font2 = TTF_OpenFont("assets/BebasNeueBold.ttf", 30);
	SDL_Color textcolour2 = { 139, 0, 0, 255 };
	SDL_Surface* textSurface2 = TTF_RenderText_Blended(font2, "WELCOME :)", textcolour2);
	 textTexture2 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface2);
	SDL_FreeSurface(textSurface2);

	 textDestination2;
	textDestination2.x = 170;
	textDestination2.y = 200;



	SDL_QueryTexture(textTexture2, NULL, NULL, &textDestination2.w, &textDestination2.h);




	//TEXT: Exit*****************************************************************
	TTF_Font* font3 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour3 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface3 = TTF_RenderText_Blended(font3, "Press Esc to Exit", textcolour3);
	 textTexture3 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface3);
	SDL_FreeSurface(textSurface3);



	 textDestination3;
	textDestination3.x = 100;
	textDestination3.y = 340;
	SDL_QueryTexture(textTexture3, NULL, NULL, &textDestination3.w, &textDestination3.h);

}


MenuGameState::~MenuGameState()
{
	//destroy and delete stuff here
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(textTexture1);
	SDL_DestroyTexture(textTexture2);
	SDL_DestroyTexture(textTexture3);
}

void MenuGameState::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		//event fired when pressing window close button
		if (e.type == SDL_QUIT)
		{
			Globals::quitGame = true;
			Globals::gsm.popState();
			return;
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				
					Globals::quitGame = true;
					Globals::gsm.popState();
				
				return;
			}
			if (e.key.keysym.scancode == SDL_SCANCODE_KP_ENTER || e.key.keysym.scancode == SDL_SCANCODE_RETURN)
			{
				//start the game
				Globals::gsm.pushState(new PlayGameState());

			}
		}
	}

}

void MenuGameState::render()
{

	//background colour
	SDL_SetRenderDrawColor(Globals::renderer, 255, 255, 255, 255);
	SDL_RenderClear(Globals::renderer);

	//load up texts
	SDL_RenderCopy(Globals::renderer, textTexture, NULL, &textDestination);
	SDL_RenderCopy(Globals::renderer, textTexture1, NULL, &textDestination1);
	SDL_RenderCopy(Globals::renderer, textTexture2, NULL, &textDestination2);
	SDL_RenderCopy(Globals::renderer, textTexture3, NULL, &textDestination3);

	SDL_RenderPresent(Globals::renderer);
	
}

bool MenuGameState::onEnter()
{
	cout << "Entering menu state" << endl;
	return true;

}
bool MenuGameState::onExit()
{
	cout << "Exiting menu state" << endl;
	return true;

}