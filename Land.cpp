#include "Land.h"

void Land::landUpdate1(bool die)
{
	if (distance1 <= -720)
	{
		distance1 = 0;
	}
	else
	{
		if (!die)
		{
			distance1--;
		}
		setDest(distance1, 600, 720, 120);
	}
}

void Land::landUpdate2(bool die)
{
	if (distance2 <= 0)
	{
		distance2 = 720;
	}
	else
	{
		if (!die)
		{
			distance2--;
		}
		setDest(distance2, 600, 720, 120);
	}
}

void Land::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}