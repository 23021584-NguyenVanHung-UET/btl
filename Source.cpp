#include "Gameloop.h"

using namespace std;

Gameloop* g = new Gameloop();

int main(int argc, char** argv)
{
	const int FPS = 50;
	const int DELAY_TIME = 1000 / FPS;
	Uint32 frameStart;
	Uint32 frameTime;
	g->InitData();
	while (g->getGameState())
	{
		frameStart = SDL_GetTicks();
		g->Event();
		g->Render();
		g->Update();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}
	}
	g->Clear();
	return 0;
}