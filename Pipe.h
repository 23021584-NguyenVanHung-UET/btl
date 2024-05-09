#ifndef PIPE_H_
#define PIPE_H_

#include <utility>
#include <ctime>
#include <iostream>
#include "TextureManager.h"

static int upper[3];  //chieu cao upper
static int xPos[3];

class Pipe : public TextureManager
{
private:
	int randMin = -373 + 30;
	int randMax = 720 - 125 - 373 - 30 - 220;
public:
	int pipe_width;
	int pipe_height;
	int lower[3];
	int space;
	Pipe();
	~Pipe();
	Pipe(int x);
	void Render(SDL_Renderer* ren);
	int random_pipe();
	void pipeupdate1(int i, bool die);
	void pipeupdate2(int i);
	int get_upper(int i);
	int get_pos(int i);
};

#endif // !PIPE_H_
