#pragma once
#include "ECS.h"
#include <SDL.h>

class SpriteComponent : public Component
{
public:
    SDL_Rect src;
    SDL_Rect dst;
    SDL_Renderer *renderer;
    const char *file;

public:
    SpriteComponent() = default;
    SpriteComponent(SDL_Renderer *renderer, int scl)
    {
        src = {0, 0, scl, scl};
        dst = {0, 0, scl, scl};

        this->renderer = renderer;

        file = "dirt2.png";
    }
};
