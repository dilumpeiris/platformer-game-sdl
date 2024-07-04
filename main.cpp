#include "game.h"



Game *game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();
    game->init("GameWindow", 800, 640);

    const int FPS = 120;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        // game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    // game->clean();
    return 0;
}
