#include "Gameloop.h"
#include <time.h>
#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
using namespace std;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int argc, char** argv)
{
	const int FPS = 50;
	const int DELAY_TIME = 1000 / FPS;
	Uint32 frameStart;
	Uint32 frameTime;
	gameloop g;
	while (1)
	{
		frameStart = SDL_GetTicks();
		g.render();
		g.update();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}
	}
	g.clear();
	return 0;
}