#include "TextureManager.h"
TextureManager::TextureManager()
{
	Tex = NULL;
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
