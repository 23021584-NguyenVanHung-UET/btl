#pragma once
#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "TextureManager.h"

class Background : public TextureManager
{
private:
public:
	void Render(SDL_Renderer* ren);
};

#endif // !BACKGROUND_H_
