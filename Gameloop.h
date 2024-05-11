#include "TextureManager.h"
#include "Background.h"
#include "Base.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class gameloop :TextureManager
{
private:
	background bg;
	base b;
public:
	gameloop();
	~gameloop();
	bool initData();
	bool isQuit() { return quit; }
	bool isDie() { return die; }
	void render();
	void update();
	void clear();
};