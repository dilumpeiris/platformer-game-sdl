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
    SpriteComponent(SDL_Renderer *renderer, const char *img, int scl_x, int scl_y)
    {
        src = {0, 0, scl_x, scl_y};
        dst = {0, 0, scl_x, scl_y};

        this->renderer = renderer;

        file = img;
    }
};
