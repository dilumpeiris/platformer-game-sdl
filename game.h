#pragma once
#include "SDL.h"
class Game {
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Game(){}

    bool isRunning = true;
    bool running() { return isRunning; }

    void init(const char *title, int width, int height);
    void update();
    void draw();
    void handleEvents();
};
