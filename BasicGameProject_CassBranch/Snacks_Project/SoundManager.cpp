#include "SoundManager.h"


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
	//DELETE ALL SOUND EFFETS PROPERLY
	for (soundListing listing : sounds)
	{
		Mix_FreeChunk(listing.sound);
	}
}

void SoundManager::loadSound(string name, string file)
{
	soundListing listing;
	listing.name = name;
	listing.sound = Mix_LoadWAV(file.c_str());//c_str returns a char*

	//add sound listing to our list of sounds
	sounds.push_back(listing);


}

void SoundManager::playSound(string name)
{
	//look for soung in list
	for (soundListing listing : sounds)
	{
		//if the listing matches the name we're searching, then play it
		if (listing.name == name)
		{
			//params: which channel to play on(-1 is whichever available), the sound to play, how many times to loop (0= no loop)
			Mix_PlayChannel(-1, listing.sound, 0);
			break;//exit the loop so we don't waste any more time looking
		}
	}
}

//initialise static member
SoundManager SoundManager::soundManager;