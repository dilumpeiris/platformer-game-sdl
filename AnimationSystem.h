#pragma once
#include "AnimationComponent.h"
#include "ECS.h"
#include "SpriteComponent.h"
#include <SDL.h>

class AnimationSystem : public System

{
public:
    AnimationSystem() {}

    void update() override
    {
        for (auto &e : manager->entities) {
            if (e->hasComponent<AnimationComponent>()) {
                AnimationComponent *a = e->getComponent<AnimationComponent>();
                SpriteComponent *s = e->getComponent<SpriteComponent>();
                s->file = a->getCurrentFrame().c_str();
                TextureManager::clearTexture(s->text);
                s->text = TextureManager::loadTexture(s->renderer, s->file);
                a->update();
            }
        }
    }
};
