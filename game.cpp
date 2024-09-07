#include "game.h"
// #include "AnimationComponent.h"
// #include "AnimationSystem.h"
#include "AnimationSystem.h"
#include "ColliderComponent.h"
#include "CollisionDetectionSystem.h"
#include "Gravity.h"
#include "PhysicsSystem.h"
#include "PlayerMovementSystem.h"
#include "SpriteComponent.h"
#include "SpriteSystem.h"

void Game::loadEntities(Manager *manager)
{
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
    player->addComponent<TransformComponent>(100, 100, 64, 64);
    player->addComponent<PhysicsComponent>();
    player->addComponent<ColliderComponent>();
    player->addComponent<SpriteComponent>(renderer, "player.png", 64, 64);

    for (int i = 0; i < 10; i++) {
        Entity *brick = manager->addEntity(1);
        brick->addComponent<TransformComponent>(i * 64, 640 - 64, 64, 64);
        brick->addComponent<SpriteComponent>(renderer, "bricks1.jpg", 64, 64);
        brick->addComponent<ColliderComponent>();
    }
}

Animation Game::createAnimation(std::string name, int total, float speed)
{
    std::vector<std::string> frames;
    for (int i = 1; i <= total; ++i) {
        frames.emplace_back(name + "-" + std::to_string(i) + ".png");
    }
    Animation animation(frames, speed);
    return animation;
}

void Game::loadAnimations(Manager *manager)
{
    for (auto &e : manager->entities) {
        switch (e->tag) {
        case 0:
            Animation walking_left = createAnimation("walking-left", 8, 50.0);
            Animation walking_right = createAnimation("walking-right", 8, 50.0);
            Animation idle_left = createAnimation("idle-left", 2, 300.0);

            e->addComponent<AnimationComponent>();
            e->getComponent<AnimationComponent>()->addAnimation("walking-left", walking_left);
            e->getComponent<AnimationComponent>()->addAnimation("walking-right", walking_right);
            e->getComponent<AnimationComponent>()->addAnimation("idle-left", idle_left);

            e->getComponent<AnimationComponent>()->current_animation = "idle-left";

            break;
        }
    }
}

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

    loadEntities(manager);
    loadAnimations(manager);

    manager->addSystem<PlayerMovementSystem>();
    manager->addSystem<Gravity>();
    manager->addSystem<CollisionDetectionSystem>();
    manager->addSystem<PhysicsSystem>();
    manager->addSystem<SpriteSystem>();
    manager->addSystem<AnimationSystem>();
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
