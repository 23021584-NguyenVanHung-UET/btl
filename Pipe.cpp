#include "Pipe.h"
#include <iostream>

vector <position> pos_pipe;

bool pipe::init()
{
	pos_pipe.clear();
	string path = "img/top.png";
	for (signed char i = 0; i < 4; i++)
	{
		position tmp;
		int x = SCREEN_WIDTH + i*PIPE_DISTANCE + 350;
		int y = (rand() % (randMax - randMin + 1)) + randMin;
		tmp.getPos(x, y);
		pos_pipe.push_back(tmp);
		cout << x << " " << y << endl;
	}
	if (isNULL())
	{
		if (CreatTexture(path.c_str(), 1))
		{
			return true;
		}
	}
	return false;
}

void pipe::Free()
{
	free();
}

void pipe::render()
{
	for (signed char i = 0; i < 4; i++)
	{
		Render(pos_pipe[i].x, pos_pipe[i].y);
		Render(pos_pipe[i].x, pos_pipe[i].y + getHeight() + PIPE_SPACE, 180);
	}
}

void pipe::update()
{
	if (die == true)
	{
		for (int i = 0; i < 4; i++)
		{
			if (pos_pipe[i].x < -getWidth())
			{
				pos_pipe[i].y = (rand() % (randMax - randMin + 1)) + randMin;
				pos_pipe[i].x = pos_pipe[(i + 4 - 1) % 4].x + PIPE_DISTANCE;
			}
			else
			{
				pos_pipe[i].x -= 3;
			}
		}
	}
}
