#include "texturemanager.h"
using namespace std;

SDL_Texture *TextureManager::loadTexture(SDL_Renderer *renderer, const char *filename)
{
    SDL_Surface *tmpSurface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}

void TextureManager::draw(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect srcR, SDL_Rect dstR)
{
    SDL_RenderCopy(renderer, texture, &srcR, &dstR);
    // clearTexture(texture);
}

void TextureManager::clearTexture(SDL_Texture *texture)
{
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
