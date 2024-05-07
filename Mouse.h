#pragma once
#ifndef MOUSE_H_
#define MOUSE_H_

#include "TextureManager.h"
class Mouse : public TextureManager
{
private:
public:
	SDL_Rect src, dest;
	Mouse();
	void Render(SDL_Renderer* ren);
};

#endif // !MOUSE_H_
