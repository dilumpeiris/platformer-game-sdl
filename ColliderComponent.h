#pragma once
#include "ECS.h"
#include <SDL.h>

class ColliderComponent : public Component
{
public:
    bool isCollided = false;
    SDL_Rect collider;

public:
    ColliderComponent() = default;
};
