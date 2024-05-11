#include "TextureManager.h"
#include <iostream>

using namespace std;
bool TextureManager::quit = false;
bool TextureManager::die = true;
short int TextureManager::score = 0;
SDL_Window* TextureManager::Window = NULL;
SDL_Renderer* TextureManager::Renderer=NULL;
SDL_Event TextureManager::event;

TextureManager::TextureManager()
{
	Texture = NULL;
}

short int TextureManager::getWidth()
{
	return Width;
}

short int TextureManager::getHeight()
{
	return Height;
}

void TextureManager::free()
{
	if (Texture != NULL)
	{
		SDL_DestroyTexture(Texture);
		Texture = NULL;
		Width = 0;
		Height = 0;
	}
}

void TextureManager::Render(short int x, short int y, short int angle, SDL_Rect* clip, SDL_RendererFlip flip)
{
	SDL_Rect Rect = { x, y, Width, Height };

	if (clip != NULL)
	{
		Rect.w = clip->w;
		Rect.h = clip->h;
	}

	SDL_RenderCopyEx(Renderer, Texture, clip, &Rect, angle, NULL, flip);
}

bool TextureManager::CreatTexture(string path, double scale)
{
	SDL_Surface* Surface = NULL;
	Surface = IMG_Load(path.c_str());
	if (Surface == NULL)
	{
		cout << "Unable to load image %s! SDL_image Error: %s\n" << path.c_str() << IMG_GetError() <<endl;
	}
	else
	{
		SDL_SetColorKey(Surface, SDL_TRUE, SDL_MapRGB(Surface->format, 0x00, 0xFF, 0xFF));

		Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
		if (Texture == NULL)
		{
			cout << "Unable to create texture from %s! SDL Error: %s\n"<< path.c_str()<< SDL_GetError()<<endl;
		}
		else
		{
			Width = (Surface->w) * scale;
			Height = (Surface->h) * scale;
		}

		SDL_FreeSurface(Surface);
	}
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	return Texture != NULL;

}

bool TextureManager::isNULL()
{
	if (Texture == NULL) return true;
	return false;
}

void position::getPos(const short int x, const short int y)
{
	this->x = x;
	this->y = y;
}