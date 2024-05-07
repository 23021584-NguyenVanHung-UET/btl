#pragma once
#include "TextureManager.h"

class Player :public TextureManager
{
private:
	double gravity = 0.2;
	int yPos = 256;
	double a1 = 0;
	double a2 = 0;
	bool inJump = false;
	double jumpHeight = -6;
	double jumpTimer;
	double lastJump = 0;
	SDL_Texture* Tex1;
	SDL_Texture* Tex2;
	int animationTimer;
public:
	void Gravity();
	void GetJumpTime();
	void Jump();
	bool JumpState();
	void CreateTexture1(const char* add, SDL_Renderer* ren);
	void CreateTexture2(const char* add, SDL_Renderer* ren);
	void Render(SDL_Renderer* ren);
};