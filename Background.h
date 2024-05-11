#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "TextureManager.h"
#include "vector"

using namespace std;

class background :TextureManager
{
private:
	position pos_bg;
public:
	bool init();
	void Free();
	void render();
	void update();
};

#endif // !BACKGROUND_H_
