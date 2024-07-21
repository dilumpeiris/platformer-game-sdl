#pragma once
#include "SDL_image.h"

class TextureManager
{
public:
    TextureManager(){};
    static void draw(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect srcR, SDL_Rect dstR);
    static SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *filename);
    static void clearTexture(SDL_Texture *texture);
};
