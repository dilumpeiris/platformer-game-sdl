#include "game.h"
#include "ECS.h"
#include <iostream>

void Game::init(const char *title, int width, int height) {
    int flags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(
            window, -1, 0
            // SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
            );
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
    }
    isRunning = true;
}



void Game::handleEvents() {
    if (SDL_PollEvent(&event)) {
        switch (Game::event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}
void Game::update() {}
void Game::draw() {}
