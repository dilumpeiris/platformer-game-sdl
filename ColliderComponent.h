#pragma once
#include "ECS.h"
#include <SDL.h>

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;

public:
    ColliderComponent() = default;
    // ColliderComponent()
    // {}
};
