#include "Background.h"

bool background::init()
{
	pos_bg.getPos(0, 0);
	string path = "img/background.png";
	if (isNULL())
	{
		if (CreatTexture(path, 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void background::Free()
{
	free();
}

void background::render()
{
	if(pos_bg.x > 0)
	{
		Render(pos_bg.x, pos_bg.y);
	}
	else
	{
		if (pos_bg.x > -SCREEN_WIDTH && pos_bg.x <= 0)
		{
			Render(pos_bg.x, pos_bg.y);
			Render(pos_bg.x + SCREEN_WIDTH, pos_bg.y, 0, NULL);
		}
		else
		{
			pos_bg.getPos(0, 0);
			Render(pos_bg.x, pos_bg.y);
		}
	}
}


void background::update()
{
	pos_bg.x -= 1;
}