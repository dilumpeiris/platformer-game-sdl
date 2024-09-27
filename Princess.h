#pragma once

#include "AnimationComponent.h"
#include "AnimationManager.h"
#include "ColliderComponent.h"
#include "ECS.h"
#include "PhysicsComponent.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
class Princess : public Entity
{
public:
    SDL_Renderer *renderer;
    SDL_Texture *sprite_sheet;
    //std::vector<Animation> animations;

    Princess(SDL_Renderer *renderer, SDL_Texture *sprite_sheet)
        : Entity(0)
        , renderer(renderer)
        , sprite_sheet(sprite_sheet)
    {
        this->addComponent<TransformComponent>(100, 100, 64, 64);
        this->addComponent<PhysicsComponent>();
        this->addComponent<ColliderComponent>();
        this->addComponent<SpriteComponent>(renderer, sprite_sheet, 864, 0, 64, 64);
        this->addComponent<AnimationComponent>();

        std::map<std::string, std::array<int, 4>> animations
            = {{"walking-left", {1092, 8, 50, true}},
               {"walking-right", {1092, 8, 50, false}},
               {"idle-left", {864, 2, 500, true}},
               {"idle-right", {864, 2, 500, false}}};

        AnimationManager::loadAnimations(animations, this);
        // Set a default animation, otherwise the program would crash due to AnimationSystem trying to access a non existing current animation
        this->getComponent<AnimationComponent>()->current_animation = "idle-right";
    }
};
