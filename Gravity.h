#pragma once
#include "ECS.h"
#include "PhysicsComponent.h"
#include <SDL.h>

class Gravity : public System

{
public:
    Gravity() {}
    void update() override
    {
        for (auto &e : manager->entities) {
            if (e->hasComponent<PhysicsComponent>()) {
                PhysicsComponent *p = e->getComponent<PhysicsComponent>();
                p->velocity.y += 1.1;
            }
        }
    }
};
