#include "Player.h"
#include<iostream>

void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}

void Player::Gravity()
{
	if (JumpState())
	{
		a1 = a1 + 0.035;
		a2 = a2 + 0.035;
		jumpHeight = jumpHeight + gravity;
		yPos =yPos + (int)(gravity + a1 + a2 + jumpHeight);
		setDest(25, yPos, 28, 38);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		}
	}
	else
	{

		a1 = a1 + 0.035;
		a2 = a2 + 0.035;
		yPos = yPos + (int)(gravity + a1 + a2);
		setDest(25, yPos, 28, 38);
	}

}

void Player::Jump()
{
	if (jumpTimer - lastJump > 180)
	{
		a1 = 0;
		a2 = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}