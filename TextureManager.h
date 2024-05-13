
#pragma once
#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class position
{
public:
    short int x, y, angle, state;
    void getPos(const short int x, const short int y);
};

class TextureManager
{
public:
    TextureManager();

    ~TextureManager() {}

    bool isNULL();

    bool CreatTexture(string path, double scale = 1);

    int getWidth();
    int getHeight();

    void free();
    void Render(short int x, short int y, short int angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
public:
    SDL_Texture* Texture;

    short int Width;
    short int Height;

public:
    static SDL_Window* Window;
    static SDL_Renderer* Renderer;
    static SDL_Event event;
    static bool quit;
    static bool die;
    static int score ;
    static const int SCREEN_WIDTH = 350;
    static const int SCREEN_HEIGHT = 625;
    static const int PIPE_SPACE = 160;
    static const int PIPE_DISTANCE = 220;
    static const int BASE_HEIGHT = 140;
    static const int BIRD_WIDTH = 50;
    static const int BIRD_HEIGHT = 35;
};

#endif // !TEXTUREMANAGER_H_