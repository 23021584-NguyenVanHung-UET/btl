#pragma once
#ifndef MOUSE_H_
#define MOUSE_H_
#include <vector>
#include "TextureManager.h"
#include <iostream>
using namespace std;



class mouse :public TextureManager
{
private:
	bool check;
public:
	SDL_Rect cursor, tip;
	mouse();
	~mouse();
	bool init();
	void render();
	position pos_mouse;
	bool check_mouse();
	
};

#endif // !MOUSE_H_
