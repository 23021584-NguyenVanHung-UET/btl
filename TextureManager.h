#pragma once
#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

using namespace std;

class TextureManager
{
private:
	SDL_Rect src, dest;
	SDL_Texture* Tex;
public:
	TextureManager();

	static SDL_Texture* Texture(const char* img_path, SDL_Renderer* ren);
	SDL_Texture* getTexture();
	SDL_Rect &getSrc();
	SDL_Rect &getDest();
	void setSrc(int x, int y, int w, int h);
	void setDest(int x, int y, int w, int h);
	void CreateTexture(const char* img_path, SDL_Renderer* ren);
	void virtual Render(SDL_Renderer* ren) = 0;
};

#endif // !TEXTUREMANAGER_H_
