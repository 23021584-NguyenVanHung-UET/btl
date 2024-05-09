#include "Land.h"

void Land::landUpdate1(bool birdDie)
{
	if (distance1 <= -720)
	{
		distance1 = 0;
	}
	else
	{
		if (!birdDie)
		{
			distance1--;
		}
		setDest(distance1, 600, 720, 120);
	}
}

void Land::landUpdate2(bool birdDie)
{
	if (distance2 <= 0)
	{
		distance2 = 720;
	}
	else
	{
		if (!birdDie)
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