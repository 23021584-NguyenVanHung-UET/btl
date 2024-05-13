#include "Sound.h"
#include <iostream>
#include <string>

bool sound::init()
{
	string path_breath = "sound/wing.wav";
	string path_hit = "sound/sfx_bonk.wav";
	string path_sound = "img/sound.png";
	bool success = true;

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		cout << "SDL can't init!!! SDL_Error " << SDL_GetError();
		success = false;
	}
	else
	{
		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048)<0)
		{
			cout << "SDL mixer can't init!!! SDL_Error " << Mix_GetError();
			success = false;
		}
		
		breath = Mix_LoadWAV(path_breath.c_str());
		if (breath == NULL)
		{
			cout << "Load mix failed!!! " << Mix_GetError();
			success = false;
		}

		hit = Mix_LoadWAV(path_hit.c_str());
		if (hit == NULL)
		{
			cout << "Load mix failed!!!" << Mix_GetError();
			success = false;
		}

		if (!CreatTexture(path_sound))
		{
			return false;
		}
		Active = { 0, 0, getWidth(), getHeight() };
		Mute = { 0, getHeight() / 2, getWidth(), getHeight() / 2 };
		isPlay = true;
	}
	return success;
}

void sound::play1()
{
	if (isPlay)
	{
		Mix_PlayChannel(-1, breath, 0);
	}
}

void sound::play2()
{
	if (!isPlay)
	{
		Mix_PlayChannel(-1, hit, 0);
	}
}
void sound::render()
{
	if (isPlay)
	{
		Render(pos_x, pos_y, 0, &Active);
	}
	else
	{
		Render(pos_x, pos_y, 0, &Mute);
	}
}

bool sound::check_sound()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > pos_x && x < pos_x + getWidth() && y>pos_y && y < pos_y + getHeight())
	{
		isPlay = !isPlay;
		return true;
	}
	return false;
}