#pragma once
#ifndef LAND_H_
#define LAND_H_

#include "TextureManager.h"

class Land :public TextureManager
{
private:
	int distance1 = 0;
	int distance2 = 720;
public:
	void landUpdate1(bool die);
	void landUpdate2(bool die);
	void Render(SDL_Renderer* ren);
};

#endif // !LAND_H_
