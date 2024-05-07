#include "Button.h"

Button::Button(SDL_Renderer* ren)
{
	check_select = false;
}

Button::Button(int x, int y)
{
	src = { x,y,384,186 };
	dest = { x,y,185,80 };
	check_select = false;
}

void Button::coordinate(int x, int y)
{
	dest.x = x;
	dest.y = y;
}

void Button::CheckSelect(Mouse* m)
{
	if (SDL_HasIntersection(&(m->src), &dest))
	{
		check_select = true;
		src.x = 400;
	}
	else
	{
		check_select = false;
		src.x = 0;
	}
}

void Button::Render(SDL_Renderer* ren, SDL_Texture* button)
{
	SDL_RenderCopy(ren, button, &src, &dest);
}