#include "game.h"
#include "PlayerMovementSystem.h"
#include "SpriteComponent.h"
#include "SpriteSystem.h"
#include <iostream>

void Game::init(const char *title, int width, int height)
{
    int flags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width,
                                  height,
                                  flags);
        renderer = SDL_CreateRenderer(window, -1, 0
                                      // SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
    }
    isRunning = true;
    manager = new Manager();

    Entity *player = manager->addEntity();
    player->addComponent<TransformComponent>(100, 100, 100);
    player->addComponent<SpriteComponent>(renderer, 100);
    manager->addSystem<SpriteSystem>();
    manager->addSystem<PlayerMovementSystem>();
}

void Game::handleEvents()
{
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
void Game::update()
{
    SDL_RenderClear(renderer);
    manager->update();
    SDL_RenderPresent(renderer);
}
void Game::draw()
{
    // SDL_RenderClear(renderer);
    // manager->draw();
    // SDL_RenderPresent(renderer);
}
