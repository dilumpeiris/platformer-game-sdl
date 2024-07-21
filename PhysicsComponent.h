#pragma once
#include "ECS.h"
#include "vector2d.h"
class PhysicsComponent : public Component
{
public:
    Vector2D velocity;
    PhysicsComponent()
    {
        velocity = 0;
    }
};
