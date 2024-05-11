#include "Base.h"

bool base::init()
{
	pos_base.getPos(0, SCREEN_HEIGHT-BASE_HEIGHT+70);
	string path = "img/base.png";

	if (isNULL())
	{
		if (CreatTexture(path.c_str()), 2)
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
void base::Free()
{
	free();
}

void base::render()
{
	if (pos_base.x > 0)
	{
		Render(pos_base.x, pos_base.y);
	}
	else
	{
		if (pos_base.x > -SCREEN_WIDTH && pos_base.x <= 0)
		{
			Render(pos_base.x, pos_base.y);
			Render(pos_base.x + SCREEN_WIDTH, pos_base.y, 0, NULL);
		}
		else
		{
			pos_base.getPos(0, SCREEN_HEIGHT - BASE_HEIGHT + 70);
			Render(pos_base.x, pos_base.y);
		}
	}
}

void base::update()
{
	pos_base.x -= 1;
}
