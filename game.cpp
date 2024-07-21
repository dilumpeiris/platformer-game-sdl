#include "game.h"
#include "ColliderComponent.h"
#include "CollisionDetectionSystem.h"
#include "Gravity.h"
#include "PhysicsSystem.h"
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

    Entity *sky = manager->addEntity(1);
    sky->addComponent<TransformComponent>(0, 0, 800, 600);
    sky->addComponent<SpriteComponent>(renderer, "sky.jpg", 800, 640);

    Entity *box = manager->addEntity(1);
    box->addComponent<TransformComponent>(300, 375, 100, 100);
    box->addComponent<SpriteComponent>(renderer, "green_block.png", 100, 100);
    box->addComponent<ColliderComponent>();

    Entity *box2 = manager->addEntity(1);
    box2->addComponent<TransformComponent>(500, 375, 100, 100);
    box2->addComponent<SpriteComponent>(renderer, "green_block.png", 100, 100);
    box2->addComponent<ColliderComponent>();

    Entity *box3 = manager->addEntity(1);
    box3->addComponent<TransformComponent>(700, 175, 100, 100);
    box3->addComponent<SpriteComponent>(renderer, "green_block.png", 100, 100);
    box3->addComponent<ColliderComponent>();

    Entity *player = manager->addEntity(0);
    player->addComponent<TransformComponent>(100, 100, 100, 100);
    player->addComponent<PhysicsComponent>();
    player->addComponent<ColliderComponent>();
    player->addComponent<SpriteComponent>(renderer, "player.png", 100, 100);

    for (int i = 0; i < 10; i++) {
        Entity *brick = manager->addEntity(1);
        brick->addComponent<TransformComponent>(i * 64, height - 64, 64, 64);
        brick->addComponent<SpriteComponent>(renderer, "bricks1.jpg", 64, 64);
        brick->addComponent<ColliderComponent>();
    }

    manager->addSystem<PlayerMovementSystem>();
    manager->addSystem<Gravity>();
    manager->addSystem<CollisionDetectionSystem>();
    manager->addSystem<PhysicsSystem>();
    manager->addSystem<SpriteSystem>();
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
}
