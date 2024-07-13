#pragma once
#include "ECS.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include <SDL.h>

class PhysicsSystem : public System

{
public:
    PhysicsSystem() {}

    void update() override
    {
        for (auto &e : manager->entities) {
            if (e->hasComponent<PhysicsComponent>()) {
                TransformComponent *t = e->getComponent<TransformComponent>();
                PhysicsComponent *p = e->getComponent<PhysicsComponent>();
                p->velocity.y += 1;
                t->position += p->velocity;
            }
        }
    }
};
