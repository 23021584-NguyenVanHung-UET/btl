#include "Gameloop.h"

Gameloop::Gameloop()
{
	window = NULL;
	renderer = NULL;
	gameState = false;
	birdDie = false;
	bg.setSrc(0, 0, WIDTH, HEIGHT);
	bg.setDest(0, 0, WIDTH, HEIGHT);
	p.setSrc(0, 0, 34, 24);
	p.setDest(24, HEIGHT / 2, 44, 34);
	base1.setSrc(0, 0, WIDTH, HEIGHT);
	base1.setDest(0, 720 - 112, WIDTH, HEIGHT);
	base2.setSrc(0, 0, WIDTH, HEIGHT);
	base2.setDest(0, 720 - 112, WIDTH, HEIGHT);
}

Gameloop::~Gameloop(){}


void Gameloop::InitData()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL can't init!!! " << SDL_GetError() << endl;
		gameState = false;
	}
	else
	{
		gameState = true;
		window = SDL_CreateWindow("Flappy Bird", 
						SDL_WINDOWPOS_CENTERED, 
						SDL_WINDOWPOS_CENTERED, 
						WIDTH, HEIGHT, 
						SDL_WINDOW_RESIZABLE);
		if (window == NULL)
		{

			gameState = false;
			cout << "Window can't init!!!" << SDL_GetError() << endl;
		}
		else
		{
			gameState = true;
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				gameState = true;
				cout << "render succeeded!!!" << endl;
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				bg.CreateTexture("img/background-day.png", renderer);
				m->CreateTexture("img/mouse.png", renderer);
				p.CreateTexture("img/yellowbird1.png", renderer);
				p.CreateTexture1("img/yellowbird2.png", renderer);
				p.CreateTexture2("img/yellowbird3.png", renderer);
				base1.CreateTexture("img/base.png", renderer);
				base2.CreateTexture("img/base.png", renderer);
				for (int i = 0; i < 3; i++)
				{
					upper[i].CreateTexture("img/top.png", renderer);
					lower[i].CreateTexture("img/bot.png", renderer);
				}
			}
			else
			{
				gameState = false;
				cout << "Render can't init!!!!" << SDL_GetError() << endl;
			}
		}
	}
}
void Gameloop::Update()
{
	base1.landUpdate1(die);
	base2.landUpdate2(die);
	upper[0].pipeupdate1(0, die);
	upper[1].pipeupdate1(1, die);
	upper[2].pipeupdate1(2, die);
	lower[0].pipeupdate2(0);
	lower[1].pipeupdate2(1);
	lower[2].pipeupdate2(2);
	
}
void Gameloop::Render()
{
	SDL_RenderClear(renderer);
	bg.Render(renderer);
	p.Render(renderer);
	m->Render(renderer);
	base1.Render(renderer);
	base2.Render(renderer);
	upper[0].Render(renderer);
	upper[1].Render(renderer);
	upper[2].Render(renderer);
	lower[0].Render(renderer);
	lower[1].Render(renderer);
	lower[2].Render(renderer);
	SDL_RenderPresent(renderer);
}

void Gameloop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

bool Gameloop::getGameState()
{
	return gameState;
}

void Gameloop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		gameState = false;
	}
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP)
		{
			if (!p.JumpState())
			{
				p.Jump();
			}
			else
			{
				p.Gravity();
			}
		}
	}
	else
		p.Gravity();
}