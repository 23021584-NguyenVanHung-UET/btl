#include "TextureManager.h"
#include "Background.h"
#include "Base.h"
#include "Pipe.h"
#include "Bird.h"
#include "Sound.h"
#include "Mouse.h"
#include "Button.h"
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
	mouse m;
	button pause;
	button start;
public:
	bool state;
	bool menu_c;
	gameloop();
	~gameloop();
	bool initData();
	void menu();
	bool gameplay();
	bool isQuit() { return quit; }
	void render();
	void Event();
	void update();
	void clear();
};