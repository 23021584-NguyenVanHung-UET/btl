#pragma once
#ifndef BUTTON_H_
#define BUTTON_H_

#include "TextureManager.h"
#include "Mouse.h"
class Button : public TextureManager
{
private:
	SDL_Texture* but_Texture;
	SDL_Rect src, dest;
public:
	bool check_select;
	Button(SDL_Renderer* ren);
	Button(int x, int y);
	void coordinate(int x, int y);
	void CheckSelect(Mouse* m);
	void Render(SDL_Renderer* ren, SDL_Texture* button);
};

#endif // !BUTTON_H_
