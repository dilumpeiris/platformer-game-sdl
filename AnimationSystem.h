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
                s->flipped = a->isAnimationFlipped();
                s->src = a->getCurrentFrame();
                a->update();
            }
        }
    }
};
