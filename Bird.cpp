#include "Bird.h"
#include "Pipe.h"
#include <vector>;

position bird_pipe;

void bird::render()
{
		Render(pos_bird.x, pos_bird.y);
		animation_timer++;
		if (animation_timer > 48)
		{
			animation_timer = 0;
		}
		if (animation_timer < 16)
		{
			if (CreatTexture(path1.c_str(), 1))
			{
				Render(pos_bird.x, pos_bird.y);
			}
		}
		if (animation_timer >= 16 && animation_timer <= 32)
		{
			if (CreatTexture(path2.c_str(), 1))
			{
				Render(pos_bird.x, pos_bird.y);
			}
		}
		if (animation_timer > 32 && animation_timer <= 48)
		{
			if (CreatTexture(path3.c_str(), 1))
			{
				Render(pos_bird.x, pos_bird.y);
			}
		}
	
	//cout << rect_pipe.x << " " << rect_pipe.y << " " << rect_pipe.w << " " << rect_pipe.h << endl;
	//cout << rect_bird.x << " " << rect_bird.y << " " << rect_bird.w << " " << rect_bird.h << endl;
}


bool bird::init()
{
	pos_bird.getPos(75, SCREEN_HEIGHT / 2 - 10);
	
	if (isNULL())
	{
		return true;
	}
	//cout << pos_bird.x << " " << pos_bird.y;
	return false;
}



void bird::gravity()
{
	rect_bird.x = 75;
	rect_bird.w = rect_bird.x + 15;
	if (jump_state())
	{
		a = a + 0.035;
		jump_height += g;
		y0 += (int)(g + 2 * a + jump_height);
		pos_bird.y = y0;
		rect_bird.y = pos_bird.y;
		rect_bird.h = rect_bird.y+ 20;
		if (jump_height > 0)
		{
			inJump = false;
			jump_height -= 7;
		}
	}
	else
	{
		a += 0.035;
		y0 += (int)(g + 2 * a);
		pos_bird.y = y0;
	}
	//cout << pos_bird.x << " " << pos_bird.y << " ";
	//cout << check_collision() << endl;
}

bool bird::check_collision()
{
	if (pos_bird.y >=460)
	{
		return true;
	}
	
	
	rect_pipe.x = pos_pipe[i].x;
	rect_pipe.w = rect_pipe.x + 60;
	rect_pipe.y = pos_pipe[i].y;
	rect_pipe.h = rect_pipe.y + 350;
	if (rect_bird.w >= rect_pipe.x && rect_bird.x <= rect_pipe.w && rect_bird.h <= rect_pipe.h) return true;
	if (rect_bird.w >= rect_pipe.x && rect_bird.x <= rect_pipe.w && rect_bird.y >= rect_pipe.h + PIPE_SPACE) return true;
	if (rect_bird.w >= rect_pipe.x && rect_bird.x<=rect_pipe.w && ((rect_bird.y <= rect_pipe.h && rect_bird.h >= rect_pipe.h)||
		(rect_bird.y<=rect_pipe.w+PIPE_SPACE+10 && rect_bird.h >= rect_pipe.w + PIPE_SPACE)))
	{
		return true;
	}
	else
	{
		i = (i + 1) % 4;
		score++;
	}
	if (pos_bird.y <= 0) return true;
	
	return false;
}

void bird::jump()
{
	if (jump_timer - last_jump > 180)
	{
		a = 0;
		inJump = true;
		last_jump = jump_timer;
	}
	else
	{
		gravity();
	}
}

void bird::get_jump_time()
{
	jump_timer = SDL_GetTicks();
}

bool bird::jump_state()
{
	return inJump;
}
