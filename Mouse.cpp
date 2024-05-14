#include "Mouse.h"
#include <string>
mouse::mouse() 
{
	check = false;
};
mouse::~mouse() {};

bool mouse::check_mouse()
{
	return check;
}
bool mouse::init()
{
	string path_mouse = "img/mouse.png";
	if (isNULL())
	{
		if (CreatTexture(path_mouse.c_str(), 2))
		{
			return true;
		}
	}
	return false;
}

void mouse::render()
{
	if (event.type == SDL_MOUSEMOTION)
	{
		//cout << event.motion.x << " " << event.motion.y << endl;
		pos_mouse.getPos(event.motion.x, event.motion.y);
	}
	Render(pos_mouse.x, pos_mouse.y);
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (pos_mouse.x >= 0 && pos_mouse.x <= 350 && pos_mouse.y >= 0 && pos_mouse.y <= 625)
		{
			check = true;
		}
		else
		{
			check = false;
		}
	}
}