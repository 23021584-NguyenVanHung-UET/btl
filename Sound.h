#pragma once
#ifndef SOUND_H_
#define SOUND_H_

#include <SDL_mixer.h>
#include <string>
#include "TextureManager.h"

using namespace std;

class sound :TextureManager
{
public:
	bool init();
	void play1();
	void play2();
	void render();
	bool check_sound();

private:
	const int pos_x = 107;
	const int pos_y = 267;
	bool isPlay = 0;
	Mix_Chunk* breath = NULL;
	Mix_Chunk* hit = NULL;
	Mix_Chunk* drop = NULL;
	SDL_Rect Mute;
	SDL_Rect Active;
};

#endif // !SOUND_H_
