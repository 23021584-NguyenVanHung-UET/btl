#include "Gameloop.h"
#include <iostream>
using namespace std; 

gameloop::gameloop()
{
	state = false;
	quit=true;
	cout << state << endl;

}

gameloop::~gameloop()
{
	
}
//start.init("img/message.png", 2);
//s.init();

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
					m.init();
					s.init();
					start.init("img/message.png", 2.0);
				}
			}
		}
	}
	return state;
}

void gameloop::render()
{
	
	if (state == true)
	{
		bg.render();
		p.render();
		b.render();
		m.render();
		bird.render();
		s.play();
	}
	else
	{
		s.play();
		bg.render();
		m.render();
		//bird.render();
		start.render(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 150);
		if (m.check_mouse() == true)
		{
			state = true;
			//cout << state << endl;
			gameplay();
		}
		else
		{
			state = false;
			//cout << state << endl;
			gameplay();
		}
	}
	//start.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 150);
	//s.render();
	SDL_RenderPresent(Renderer);
	SDL_RenderClear(Renderer);
}

void gameloop::update()
{
	bg.update();
	if (state == true)
	{
		p.update();
	}
	
	b.update();
	if (bird.check_collision() == true)
	{
		s.play2();
		//cout << score << endl;
		state = false;
		quit = false;
	}

	//cout << m.check_mouse() << " ";
	//bird.update();
}
void gameloop::clear()
{
	bg.Free();
	b.Free();
	m.free();
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
		quit = false;
	}
	if (state == true)
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_UP)
			{
				s.play1();
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
}



