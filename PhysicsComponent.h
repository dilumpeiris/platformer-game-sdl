#pragma once
#include "ECS.h"
#include "vector2d.h"
class PhysicsComponent : public Component
{
public:
    int weight;
    Vector2D velocity;
    Vector2D acceleration;
    PhysicsComponent()
    {
        weight = 1;
        velocity = 0;
        acceleration = {0, 0};
    }
};
