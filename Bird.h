#pragma once
#ifndef BIRD_H_
#define BIRD_H_

#include "TextureManager.h"
#include "Pipe.h"
#include <iostream>
#include <vector>

using namespace std;

static position pos_bird;

class bird :TextureManager
{
private:
	double g = 0.2;
	int i = 0;
	int y0 = 256;
	double a = 0;
	bool inJump = false;
	double jump_height = -7;
	double jump_timer;
	double last_jump = 0;
	int animation_timer;
	SDL_Rect rect_bird;
	SDL_Rect rect_pipe;
public:
	void gravity();
	void get_jump_time();
	void jump();
	bool jump_state();
	void render();
	bool init(); 
	bool check_collision();

};

#endif // !BIRD_H_
