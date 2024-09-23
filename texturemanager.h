#pragma once
#include "SDL_image.h"
#include <string>

class TextureManager
{
public:
    TextureManager(){};
    static SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *filename);
    static void draw(SDL_Renderer *renderer,
                     SDL_Texture *texture,
                     SDL_Rect srcR,
                     SDL_Rect dstR,
                     SDL_RendererFlip flip);
    static void clearTexture(SDL_Texture *texture);
};
