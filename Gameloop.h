#pragma once
#ifndef GAMELOOP_H_
#define GAMELOOP_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "Background.h"
#include "Player.h"
#include "Mouse.h"
#include "Pipe.h"
using namespace std;


class Gameloop
{
private:
	const int HEIGHT = 640;//32 tiles
	const int WIDTH = 800;//40 tiles
	bool gameState;
	bool birdDie;
	SDL_Window* window ;
	SDL_Renderer* renderer ;
	Background bg;
	SDL_Event event;
	Player p;
	Mouse* m = new Mouse;

public:
	Gameloop();
	~Gameloop();
	void InitData();
	void Event();
	void Update();
	bool getGameState();
	void Render();
	void Clear();

};

#endif // !GAMELOOP_H_
