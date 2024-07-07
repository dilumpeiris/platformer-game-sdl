#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include <SDL.h>

class PlayerMovementSystem : public System

{
public:
    std::vector<Uint8> state;
    Vector2D velocity_dir;
    PlayerMovementSystem()
    {
        const Uint8 *const_state = SDL_GetKeyboardState(nullptr);
        state.reserve(SDL_NUM_SCANCODES);
        for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
            state[i] = const_state[i];
        }
    }
    void update() override
    {
        const Uint8 *new_state = SDL_GetKeyboardState(nullptr);

        if (new_state[SDL_SCANCODE_W]) {
            velocity_dir.y = -1;
        }
        if (state[SDL_SCANCODE_W] and !new_state[SDL_SCANCODE_W]) {
            velocity_dir.y = 0;
        }
        if (new_state[SDL_SCANCODE_A]) {
            velocity_dir.x = -1;
            // transform->resolveCollisionX();
        }
        if (state[SDL_SCANCODE_A] and !new_state[SDL_SCANCODE_A]) {
            velocity_dir.x = 0;
        }
        if (new_state[SDL_SCANCODE_S]) {
            velocity_dir.y = 1;
            // transform->resolveCollisionY();
        }
        if (state[SDL_SCANCODE_S] and !new_state[SDL_SCANCODE_S]) {
            velocity_dir.y = 0;
        }
        if (new_state[SDL_SCANCODE_D]) {
            velocity_dir.x = 1;
            // transform->resolveCollisionX();
        }
        if (state[SDL_SCANCODE_D] and !new_state[SDL_SCANCODE_D]) {
            velocity_dir.x = 0;
        }

        for (auto &e : manager->entities) {
            if (e->hasComponent<TransformComponent>()) {
                TransformComponent *t = e->getComponent<TransformComponent>();
                t->position += velocity_dir * 5;
            }
        }

        for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
            state[i] = new_state[i];
        }
    }
};
