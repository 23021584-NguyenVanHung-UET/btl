#include "Gameloop.h"
#include <iostream>
using namespace std; 

gameloop::gameloop()
{
	state = true;
	cout << state << endl;

}

gameloop::~gameloop()
{
	
}

bool gameloop::initData()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL can't init!!! SDL Error: " << SDL_GetError();
		state = false;
	}
	else
	{
		Window = SDL_CreateWindow("Flappy Bird Ver 2024", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (Window == NULL)
		{
			cout << "Window can't created!!! SDL_Error " << SDL_GetError();
			state = false;
		}
		else
		{
			Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (Renderer == NULL)
			{
				state = false;
				cout << "Renderer can't create!!! SDL_Error  " << SDL_GetError();
			}
			else
			{
				if (!(IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG))
				{
					cout << "SDL IMG can't init!!! SDL_image Error " << IMG_GetError();
					state = false;
				}
				else
				{
					bg.init();
					p.init();
					b.init();
					bird.init();
					s.init();
				}
			}
			
		}
	}
	return state;
}

void gameloop::render()
{
	bg.render();
	p.render();
	b.render();
	bird.render();
	s.render();
	s.play1();
	SDL_RenderPresent(Renderer);
	SDL_RenderClear(Renderer);
}

void gameloop::update()
{
	bg.update();
	p.update();
	b.update();
	if (bird.check_collision() == true)
	{
		cout << score << endl;
		state = false;
	}
}
void gameloop::clear()
{
	bg.Free();
	b.Free();
	p.Free();
}

bool gameloop::gameplay()
{
	return state;
}
void gameloop::Event()
{
	bird.get_jump_time();
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		state = false;
	}
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP)
		{
			if (!bird.jump_state())
			{
				bird.jump();
			}
			else
			{
				bird.gravity();
			}
		}
	}
	else
		bird.gravity();
}



