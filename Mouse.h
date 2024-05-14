#pragma once
#ifndef MOUSE_H_
#define MOUSE_H_
#include <vector>
#include "TextureManager.h"
#include <iostream>
using namespace std;


class mouse :public TextureManager
{
public:
	SDL_Rect cursor, tip;
	mouse();
	~mouse();
	bool init();
	void render();
	position pos_mouse;

};

#endif // !MOUSE_H_
