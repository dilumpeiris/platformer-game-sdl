#pragma once
#include "AnimationComponent.h"
#include "ECS.h"
#include "PhysicsComponent.h"
#include <SDL.h>

class PlayerMovementSystem : public System

{
public:
    const int speed = 3;
    float jumpForce = -25.0f;

    bool isJumping = false;
    bool isGrounded = false;

    bool horizontalMovement = false;

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
        for (auto &e : manager->entities) {
            if (e->tag == 0) {
                PhysicsComponent *p = e->getComponent<PhysicsComponent>();
                AnimationComponent *a = e->getComponent<AnimationComponent>();
                handleMovement(p->velocity, isJumping, isGrounded, state, a);
                handleJumping(p->velocity, isJumping, isGrounded);
            }
        }
    }

    void handleJumping(Vector2D &velocity, bool &isJumping, bool &isGrounded)
    {
        if (isJumping) {
            velocity.y = jumpForce;
            isJumping = false;
        }
    }
    void handleMovement(Vector2D &velocity,
                        bool &isJumping,
                        bool &isGrounded,
                        std::vector<Uint8> &state,
                        AnimationComponent *a)
    {
        if (velocity.y == 0) {
            isGrounded = true;
        } else {
            isGrounded = false;
        }
        const Uint8 *new_state = SDL_GetKeyboardState(nullptr);

        if (new_state[SDL_SCANCODE_A]) {
            velocity.x = -1 * speed;
            a->current_animation = "walking-left";
            // a->state = 1;
            // transform->resolveCollisionX();
        }
        if (state[SDL_SCANCODE_A] and !new_state[SDL_SCANCODE_A]) {
            velocity.x = 0;
            a->current_animation = "idle-left";
        }

        if (new_state[SDL_SCANCODE_D]) {
            // a->state = 0;
            a->current_animation = "walking-right";
            velocity.x = 1 * speed;
        }
        if (state[SDL_SCANCODE_D] and !new_state[SDL_SCANCODE_D]) {
            velocity.x = 0;
            a->current_animation = "idle-left";
        }

        if (new_state[SDL_SCANCODE_SPACE] && isGrounded) {
            isJumping = true;
            isGrounded = false;
        }
        if (state[SDL_SCANCODE_SPACE] and new_state[SDL_SCANCODE_SPACE]) {
            isJumping = false;
        }

        if (horizontalMovement) {
            if (new_state[SDL_SCANCODE_W]) {
                velocity.y = -1 * speed;
            }
            if (state[SDL_SCANCODE_W] and !new_state[SDL_SCANCODE_W]) {
                velocity.y = 0;
            }
            if (new_state[SDL_SCANCODE_S]) {
                velocity.y = 1 * speed;
            }
            if (state[SDL_SCANCODE_S] and !new_state[SDL_SCANCODE_S]) {
                velocity.y = 0;
            }
        }

        for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
            state[i] = new_state[i];
        }
    }
};
