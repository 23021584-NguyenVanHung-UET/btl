#include "Mouse.h"

Mouse::Mouse()
{
	src = { 0,0,25,25 };
	dest = { 0,0,1,1 };
}

void Mouse::Render(SDL_Renderer* ren)
{
	dest.x = src.x;
	dest.y = src.y;

	SDL_RenderCopy(ren, getTexture(), NULL, &src);
}