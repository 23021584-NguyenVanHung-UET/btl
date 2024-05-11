#pragma once
#ifndef BASE_H_
#define BASE_H_

#include "TextureManager.h"

class base :TextureManager
{
private:
	position pos_base;
public:
	bool init();
	void render();
	void update();
	void Free();
};

#endif // !BASE_H_
