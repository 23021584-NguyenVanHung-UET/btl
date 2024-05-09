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
#include "Land.h"

using namespace std;


class Gameloop
{
private:
	const int HEIGHT = 720;//32 tiles
	const int WIDTH = 540;//40 tiles
	bool gameState;
	bool birdDie;
	SDL_Window* window ;
	SDL_Renderer* renderer ;
	Background bg;
	SDL_Event event;
	Player p;
	Mouse* m = new Mouse;
	Land base1, base2;
	Pipe upper[3], lower[3];
	bool die = false;
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
