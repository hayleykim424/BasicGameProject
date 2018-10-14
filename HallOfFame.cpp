#include "HallOfFame.h"


HallOfFame::HallOfFame()
{
<<<<<<< HEAD
	font11 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);

	
	//Load Highschore
	ifstream hiScoreFile;
	ofstream myFile;
	int highScore;
	int score = Globals::heroScore;
=======
	font1 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);

	/*
	//Load Highschore
	ifstream hiScoreFile;
	ofstream myFile;
	int highScore = 0;
>>>>>>> 028c64060f9cb77c3c7ad1460b06bfd87328dd35

	hiScoreFile.open("highscore.txt");

	if (hiScoreFile.good())
	{
		hiScoreFile >> highScore;
	}
	hiScoreFile.close();
<<<<<<< HEAD
	

	if (score > highScore)
	{
		highScore = score;
		myFile.open("highscore.txt", ios::trunc);

		myFile << score << endl;
		myFile.close();
	}

	
	//Load up TEXT: HALL OF FAME***********************************************************
	//								font file path				font size
	TTF_Font *font00 = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 64);
	//create a colour for our text
	SDL_Color textcolour00 = { 0, 0, 0, 255 }; //RGBA
	//Create surface using font, colour and desired output text
	SDL_Surface* textSurface00 = TTF_RenderText_Blended(font00, "HALL OF FAME", textcolour00);
	//convert suface to texture
	textTexture00 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface00);
	//don't need the surface no more
	SDL_FreeSurface(textSurface00);

	//setup rectangle to describe where to draw this text
	textDestination00;
	textDestination00.x = 27;
	textDestination00.y = 100;
	//to get the width and height, query the surface
	SDL_QueryTexture(textTexture00, NULL, NULL, &textDestination00.w, &textDestination00.h);

	//TEXT: HIGH SCORE*****************************************************************

	TTF_Font* font22 = TTF_OpenFont("assets/BebasNeueBold.ttf", 30);
	SDL_Color textcolour22 = { 139, 0, 0, 255 };
	SDL_Surface* textSurface22 = TTF_RenderText_Blended(font22, "GAME OVER", textcolour22);
	textTexture22 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface22);
	SDL_FreeSurface(textSurface22);

	textDestination22;
	textDestination22.x = 170;
	textDestination22.y = 200;


	SDL_QueryTexture(textTexture22, NULL, NULL, &textDestination22.w, &textDestination22.h);


	//TEXT: Your Score*****************************************************************
	
	TTF_Font* font44 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour44 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface44 = TTF_RenderText_Blended(font44, "Your Score: ", textcolour44);
	textTexture44 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface44);
	SDL_FreeSurface(textSurface44);


	textDestination44;
	textDestination44.x = 100;
	textDestination44.y = 270;
	SDL_QueryTexture(textTexture44, NULL, NULL, &textDestination44.w, &textDestination44.h);
	
	//TEXT: Highscore*****************************************************************
	TTF_Font* font55 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour55 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface55 = TTF_RenderText_Blended(font55, "High Score: ", textcolour55);
	textTexture55 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface55);
	SDL_FreeSurface(textSurface55);


	textDestination55;
	textDestination55.x = 100;
	textDestination55.y = 330;
	SDL_QueryTexture(textTexture55, NULL, NULL, &textDestination55.w, &textDestination55.h);



	//TEXT: Exit*****************************************************************
	TTF_Font* font33 = TTF_OpenFont("assets/BebasNeueBold.ttf", 45);
	SDL_Color textcolour33 = { 0, 0, 0, 255 };
	SDL_Surface* textSurface33 = TTF_RenderText_Blended(font33, "Press Esc to Exit", textcolour33);
	textTexture33 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface33);
	SDL_FreeSurface(textSurface33);


	textDestination33;
	textDestination33.x = 100;
	textDestination33.y = 380;
	SDL_QueryTexture(textTexture33, NULL, NULL, &textDestination33.w, &textDestination33.h);



	//TEXT: high score (display)*****************************************************************

	string st = to_string(highScore);
	st.c_str();

	textcolour66 = { 0, 0, 0, 255 };
	textSurface66 = TTF_RenderText_Blended(font11, st.c_str(), textcolour66);
	textTexture66 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface66);
	SDL_FreeSurface(textSurface66);

	textDestination66;
	textDestination66.x = 285;
	textDestination66.y = 330;

	SDL_QueryTexture(textTexture66, NULL, NULL, &textDestination66.w, &textDestination66.h);

	
=======
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
>>>>>>> 028c64060f9cb77c3c7ad1460b06bfd87328dd35
}


HallOfFame::~HallOfFame()
{
	//cleanup dynamic memory
<<<<<<< HEAD
	SDL_DestroyTexture(textTexture00);
	SDL_DestroyTexture(textTexture11);
	SDL_DestroyTexture(textTexture22);
	SDL_DestroyTexture(textTexture33);
	SDL_DestroyTexture(textTexture44);
	SDL_DestroyTexture(textTexture55);
	SDL_DestroyTexture(textTexture66);
=======
	SDL_DestroyTexture(textTexture1);
	//SDL_DestroyTexture(textTexture2);
	//SDL_DestroyTexture(textTexture3);
>>>>>>> 028c64060f9cb77c3c7ad1460b06bfd87328dd35
}



void HallOfFame::update()
{

	int x = Globals::heroScore;
	string s = to_string(x);
	s.c_str();

	//TEXT: Your Score*****************************************************************
	
<<<<<<< HEAD
	textcolour11 = { 0, 0, 0, 255 };
	textSurface11 = TTF_RenderText_Blended(font11, s.c_str() , textcolour11);
	textTexture11 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface11);
	SDL_FreeSurface(textSurface11);

	textDestination11;
	textDestination11.x = 285;
	textDestination11.y = 270;

	SDL_QueryTexture(textTexture11, NULL, NULL, &textDestination11.w, &textDestination11.h);

	
=======
	textcolour1 = { 0, 0, 0, 255 };
	textSurface1 = TTF_RenderText_Blended(font1, s.c_str() , textcolour1);
	textTexture1 = SDL_CreateTextureFromSurface(Globals::renderer, textSurface1);
	SDL_FreeSurface(textSurface1);

	textDestination1;
	textDestination1.x = 80;
	textDestination1.y = 270;

	SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);
>>>>>>> 028c64060f9cb77c3c7ad1460b06bfd87328dd35


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
<<<<<<< HEAD
	SDL_RenderCopy(Globals::renderer, textTexture00, NULL, &textDestination00);
	SDL_RenderCopy(Globals::renderer, textTexture11, NULL, &textDestination11);
	SDL_RenderCopy(Globals::renderer, textTexture22, NULL, &textDestination22);
	SDL_RenderCopy(Globals::renderer, textTexture33, NULL, &textDestination33);
	SDL_RenderCopy(Globals::renderer, textTexture44, NULL, &textDestination44);
	SDL_RenderCopy(Globals::renderer, textTexture55, NULL, &textDestination55);
	SDL_RenderCopy(Globals::renderer, textTexture66, NULL, &textDestination66);
=======
	//SDL_RenderCopy(Globals::renderer, textTexture, NULL, &textDestination);
	SDL_RenderCopy(Globals::renderer, textTexture1, NULL, &textDestination1);
	//SDL_RenderCopy(Globals::renderer, textTexture2, NULL, &textDestination2);
	//SDL_RenderCopy(Globals::renderer, textTexture3, NULL, &textDestination3);

>>>>>>> 028c64060f9cb77c3c7ad1460b06bfd87328dd35
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