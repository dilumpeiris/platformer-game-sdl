#pragma once
#include "ECS.h"
#include "vector2d.h"
#include <SDL.h>

class TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D scale;

public:
    TransformComponent() = default;
    TransformComponent(int x, int y, int scl)
    {
        position.x = x;
        position.y = y;
        scale = scl;
    }
};
