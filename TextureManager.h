#pragma once
#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

using namespace std;
class position
{
public:
	short int x, y, angle, state;
	void getPos(const short int x, const short int y);
};

class TextureManager
{
private:
	SDL_Rect src, dest;
	SDL_Texture* Tex;
	int width, height;
public:
	TextureManager();

	static SDL_Texture* Texture(const char* img_path, SDL_Renderer* ren);
	void CreateTexture(const char* img_path, SDL_Renderer* ren);
	void Render(int x, int y, double angle = 0, SDL_Rect* clip = NULL , 
		SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Renderer* ren = NULL);
	void setSrc(int x, int y, int w, int h);
	void setDest(int x, int y, int w, int h);
	int getHeight();
	int getWidth();
	SDL_Texture* getTexture();
	SDL_Rect &getSrc();
	SDL_Rect &getDest();
	void Free();

	static const short int SCREEN_WIDTH = 720;
	static const short int SCREEN_HEIGHT = 540;
	static const short int PIPE_SPACE = 160;
	static const short int TOTAL_PIPE = 4;
	static const short int PIPE_DISTANCE = 220;
	static const short int LAND_HEIGHT = 140;
	static const int WIDTH;
	static const int HEIGHT;
};

#endif // !TEXTUREMANAGER_H_
