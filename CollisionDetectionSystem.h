#pragma once
#include "ColliderComponent.h"
#include "Collision.h"
#include "ECS.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include <SDL.h>

class CollisionDetectionSystem : public System

{
public:
    std::vector<ColliderComponent *> colliders;

    CollisionDetectionSystem() {}

    void update() override
    {
        for (auto &e : manager->entities) {
            TransformComponent *t = e->getComponent<TransformComponent>();
            if (e->hasComponent<ColliderComponent>()) {
                ColliderComponent *c = e->getComponent<ColliderComponent>();
                c->collider.x = t->position.x;
                c->collider.y = t->position.y;
                c->collider.w = t->scale.x;
                c->collider.h = t->scale.y;
            }
        }
        for (auto &e : manager->entities) {
            if (e->tag == 0 && e->hasComponent<ColliderComponent>()) {
                ColliderComponent *c = e->getComponent<ColliderComponent>();
                c->isCollided = false;
                if (e->hasComponent<PhysicsComponent>()) {
                    PhysicsComponent *p = e->getComponent<PhysicsComponent>();
                    for (auto &second_e : manager->entities) {
                        if (second_e->hasComponent<ColliderComponent>() && second_e->tag != 0) {
                            ColliderComponent *second_c = second_e->getComponent<ColliderComponent>();
                            SDL_Rect rect_origin = c->collider;
                            SDL_Rect rect = second_c->collider;
                            rect.w = second_c->collider.w + c->collider.w;
                            rect.h = second_c->collider.h + c->collider.h;
                            rect.x = second_c->collider.x - c->collider.w / 2;
                            rect.y = second_c->collider.y - c->collider.h / 2;
                            const Vector2D velocity = p->velocity;

                            Vector2D contact_normal;
                            Vector2D contact_point;
                            float t_near;
                            float t_far;
                            if (Collision::DynamicRayVSRect(rect_origin,
                                                            rect,
                                                            velocity,
                                                            contact_normal,
                                                            contact_point,
                                                            t_near,
                                                            t_far)) {
                                p->velocity.x += (1 - t_near) * contact_normal.x
                                                 * abs(p->velocity.x);
                                p->velocity.y += (1 - t_near) * contact_normal.y
                                                 * abs(p->velocity.y);
                            }
                        }
                    }
                }
            }
        }
    }
};
