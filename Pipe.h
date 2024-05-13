#ifndef PIPE_H_
#define PIPE_H_

#include "TextureManager.h"
#include <iostream>
#include <vector>

extern	vector<position> pos_pipe;

class pipe :TextureManager
{
private:
	const int randMin = -373 + 30;
	const int randMax = SCREEN_HEIGHT - BASE_HEIGHT - 373 - PIPE_DISTANCE - 30;
	
public:
	bool init();
	void Free();
	void render();
	void update();
	int width() { return getWidth(); }
	int height() { return getHeight(); }
};

#endif // !PIPE_H_
