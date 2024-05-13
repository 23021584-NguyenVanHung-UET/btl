#include "TextureManager.h"
#include "Background.h"
#include "Base.h"
#include "Pipe.h"
#include "Bird.h"
#include "Sound.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class gameloop :TextureManager
{
private:
	background bg;
	base b;
	pipe p;
	sound s;
	bird bird;
public:
	bool state;
	gameloop();
	~gameloop();
	bool initData();
	bool gameplay();
	bool isQuit() { return quit; }
	bool isDie() { return die; }
	void render();
	void Event();
	void update();
	void clear();
};