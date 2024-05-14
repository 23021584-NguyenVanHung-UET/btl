#pragma once
#ifndef BUTTON_H_
#define BUTTON_H_

#include "TextureManager.h"
#include <iostream>

using namespace std;

class button :TextureManager
{
public:
	bool init(string path, double scale);
	void render(int x, int y);
	position pos_button;
};

#endif // !BUTTON_H_
