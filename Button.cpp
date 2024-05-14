#include "Button.h"

bool button::init(string path, double scale)
{
	if (isNULL())
	{
		if (CreatTexture(path.c_str()), scale)
		{
			return true;
		}
	}
	return false;
}

void button::render(int x, int y)
{
	Render(x, y);
}