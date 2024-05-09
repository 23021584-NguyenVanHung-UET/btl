#include "TextureManager.h"

TextureManager::TextureManager()
{
	Tex = NULL;
	width = 0;
	height = 0;
	src = { 0,0,0,0 };
	dest = { 0,0,0,0 };
}
SDL_Texture* TextureManager::Texture(const char* img_path, SDL_Renderer* ren)
{
	SDL_Texture* tex = NULL;
	SDL_Surface* surface = NULL;
	surface = IMG_Load(img_path);
	if (surface == NULL)
	{
		cout << "IMG can't load!!!" << SDL_GetError() << endl;
	}
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
		tex = SDL_CreateTextureFromSurface(ren, surface);
		if (tex == NULL)
		{
			cout << "Create Texture failed !!! " << SDL_GetError() << endl;
		}
	}

	return tex;
}

SDL_Texture* TextureManager::getTexture()
{
	return Tex;
}

SDL_Rect& TextureManager::getSrc()
{
	return src;
}
void TextureManager::setSrc(int x, int y, int w, int h)
{
	src = { x,y,w, h };
}
SDL_Rect& TextureManager::getDest()
{
	return dest;
}
void TextureManager::setDest(int x, int y, int w, int h)
{
	dest = { x,y,w, h };
}

void TextureManager::CreateTexture(const char* img_path, SDL_Renderer* ren)
{
	Tex = TextureManager::Texture(img_path, ren);
}

void TextureManager::Free()
{
	if (Tex != NULL)
	{
		SDL_DestroyTexture(Tex);
		Tex = NULL;
	}
}

void TextureManager::Render(int x, int y, double angle, SDL_Rect* clip, 
							SDL_RendererFlip flip, SDL_Renderer* ren)
{
	SDL_Rect Rect_Render = { x,y,NULL, NULL };
	if (clip != NULL)
	{
		Rect_Render.w = clip->w;
		Rect_Render.h = clip->h;
	}

	SDL_RenderCopyEx(ren, Tex, clip, &Rect_Render, angle, NULL, flip);
}

int TextureManager::getHeight()
{
	return height;
}
int TextureManager::getWidth()
{
	return width;
}
void position::getPos(const short int x, const short int y)
{
	this->x = x;
	this->y = y;
}

