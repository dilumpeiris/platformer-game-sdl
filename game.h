#pragma once
#include "AnimationComponent.h"
#include "ECS.h"
#include "SDL.h"
class Game
{
public:
    Manager *manager;
    SDL_Texture *sprite_sheet;

    SDL_Window *window;
    SDL_Event event;
    SDL_Renderer *renderer;

    Game() {}

    bool isRunning = true;
    bool running() { return isRunning; }

    void init(const char *title, int width, int height);
    void update();
    void draw();
    void handleEvents();
    void loadEntities(Manager *manager);
    void loadAnimations(Manager *manager);
    void loadSpriteSheet(std::string filename);
    Animation createAnimation(
        std::string name, int start, int total, float speed, bool flipped = false, int scale = 64);
};
