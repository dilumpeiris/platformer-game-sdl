#pragma once
#include "ECS.h"
#include "texturemanager.h"
#include <SDL.h>

class SpriteComponent : public Component
{
public:
    SDL_Texture *spritesheet;
    SDL_Renderer *renderer;

    SDL_Rect src;
    SDL_Rect dst;

    bool flipped = false;

    SpriteComponent() = default;
    SpriteComponent(
        SDL_Renderer *renderer, SDL_Texture *spritesheet, int src_x, int src_y, int scl_x, int scl_y)
    {
        src = {src_x, src_y, scl_x, scl_y};
        dst = {0, 0, scl_x, scl_y};

        this->renderer = renderer;
        this->spritesheet = spritesheet;
    }

    void update()
    {
        if (flipped) {
            TextureManager::draw(renderer, spritesheet, src, dst, SDL_FLIP_HORIZONTAL);
        } else {
            TextureManager::draw(renderer, spritesheet, src, dst, SDL_FLIP_NONE);
        }
    }
};
