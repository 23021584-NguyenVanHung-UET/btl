#include "Pipe.h"

Pipe::Pipe()
{
	pipe_width = 80;
	pipe_height = 180;
	space = 190;
}
Pipe::~Pipe(){}

int Pipe::random_pipe()
{
	return rand() * rand() % (randMax - randMin + 1) + randMin;
}
int Pipe::get_pos(int i)
{
	return xPos[i];
}
int Pipe::get_upper(int i)
{
	return upper[i];
}
Pipe::Pipe(int x)
{
	srand(time(nullptr));
	xPos[3] = (x + 4) * 320;
	upper[x] = Pipe::random_pipe();
	lower[x] = upper[x] + space;
	setDest(xPos[x], upper[x] - pipe_height, pipe_width, pipe_height);
}

void Pipe::pipeupdate1(int i, bool die)
{
	if (xPos[i] <= -pipe_width)
	{
		upper[i] = Pipe::random_pipe();
		xPos[i] = 190;
	}
	else
	{
		if (!die)
		{
			xPos[i]--;
			setDest(xPos[i], upper[i] - pipe_height, pipe_width, pipe_height);
		}
	}
}

void Pipe::pipeupdate2(int i)
{
	lower[i] = upper[i] + space;
	setSrc(0, 0, 125, 180);
	setDest(xPos[i], lower[i], pipe_width, pipe_height);
}

void Pipe::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}