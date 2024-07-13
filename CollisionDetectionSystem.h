#pragma once
#include "ColliderComponent.h"
#include "ECS.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include <SDL.h>

class CollisionDetectionSystem : public System

{
public:
    std::vector<ColliderComponent *> colliders;

    CollisionDetectionSystem()
    {
        for (auto &e : manager->entities) {
            if (e->hasComponent<ColliderComponent>()) {
                // TransformComponent *t = e->getComponent<TransformComponent>();
                ColliderComponent *c = e->getComponent<ColliderComponent>();
                // c->collider.x = t->position.x;
                // c->collider.y = t->position.y;
                // c->collider.w = t->scale.x;
                // c->collider.h = t->scale.y;
                // for (auto &e : manager->entities) {
                //     if (e->hasComponent<ColliderComponent>()) {
                //     }
                // }
                colliders.emplace_back(std::move(c));
            }
        }
    }

    void update() override {}
};
