#include "Mouse.h"
#include <string>
mouse::mouse() {};
mouse::~mouse() {};
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
		cout << event.motion.x << " " << event.motion.y << endl;
		pos_mouse.getPos(event.motion.x, event.motion.y);
	}
	Render(pos_mouse.x, pos_mouse.y);
}