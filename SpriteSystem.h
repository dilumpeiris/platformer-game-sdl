#pragma once
#include "ECS.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "texturemanager.h"
#include <SDL.h>

class SpriteSystem : public System
{
    void update() override
    {
        for (auto &e : manager->entities) {
            if (e->hasComponent<SpriteComponent>()) {
                SpriteComponent *s = e->getComponent<SpriteComponent>();
                TransformComponent *t = e->getComponent<TransformComponent>();
                s->dst.x = t->position.x;
                s->dst.y = t->position.y;

                s->update();
                // std::cout << s->file << std::endl;
            }
        }
    }
};
