#include "HallOfFame.h"


HallOfFame::HallOfFame()
{
	font1 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);

	/*
	//Load Highschore
	ifstream hiScoreFile;
	ofstream myFile;
	int highScore = 0;

	hiScoreFile.open("highscore.txt");

	if (hiScoreFile.good())
	{
		hiScoreFile >> highScore;
	}
	hiScoreFile.close();
	*/

	/*
	//Load up TEXT: HALL OF FAME***********************************************************
	//								font file path				font size
	TTF_Font *font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 64);
	//create a colour for our text
	SDL_Color textcolour = { 0, 0, 0, 255 }; //RGBA
	//Create surface using font, colour and desired output text
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "HALL OF FAME", textcolour);
	//convert suface to texture
	textTexture = SDL_CreateTextureFromSurface(Globals::renderer, textSurface);
	//don't need the surface no more
	SDL_FreeSurface(textSurface);

	//setup rectangle to describe where to draw this text
	textDestination;
	textDestination.x = 27;
	textDestination.y = 100;
	//to get the width and height, query the surface
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

	//TEXT: HIGH SCORE*****************************************************************

	TTF_Font* font2 = TTF_OpenFont("assets/BebasNeueBold.ttf", 30);
	SDL_Color textcolour2 = { 139, 0, 0, 255 };
	SDL_Surface* textSurface2 = TTF_RenderText_Blended(font2, "GAME OVER", textcolour2);
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
	*/
}


HallOfFame::~HallOfFame()
{
	//cleanup dynamic memory
	SDL_DestroyTexture(textTexture1);
	//SDL_DestroyTexture(textTexture2);
	//SDL_DestroyTexture(textTexture3);
}



void HallOfFame::update()
{

	int x = Globals::heroScore;
	string s = to_string(x);
	s.c_str();

	//TEXT: Your Score*****************************************************************
	
	textcolour1 = { 0, 0, 0, 255 };
	textSurface1 = TTF_RenderText_Blended(font1, s.c_str() , textcolour1);
	textTexture1 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface1);
	SDL_FreeSurface(textSurface1);

	textDestination1;
	textDestination1.x = 80;
	textDestination1.y = 270;

	SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);


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
		}
	}

}

void HallOfFame::render()
{

	//background colour
	SDL_SetRenderDrawColor(Globals::renderer, 255, 255, 255, 255);
	SDL_RenderClear(Globals::renderer);

	//load up texts
	//SDL_RenderCopy(Globals::renderer, textTexture, NULL, &textDestination);
	SDL_RenderCopy(Globals::renderer, textTexture1, NULL, &textDestination1);
	//SDL_RenderCopy(Globals::renderer, textTexture2, NULL, &textDestination2);
	//SDL_RenderCopy(Globals::renderer, textTexture3, NULL, &textDestination3);

	SDL_RenderPresent(Globals::renderer);

}
bool HallOfFame::onEnter()
{
	cout << "Entering menu state" << endl;
	return true;

}

bool HallOfFame::onExit()
{
	cout << "Exiting Hall of Fame state" << endl;
	return true;

}