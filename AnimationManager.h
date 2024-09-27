#pragma once
#include "AnimationComponent.h"
#include <SDL.h>
#include <iostream>
class AnimationManager
{
public:
    static Animation createAnimation(
        std::string name, int start, int total, float speed, bool flipped = false, int scale = 64)
    {
        std::vector<SDL_Rect> frame_sources;
        for (int i = 0; i < total; ++i) {
            SDL_Rect src = {start + (i * scale), 0, scale, scale};
            frame_sources.emplace_back(src);
        }
        Animation animation(frame_sources, speed, flipped);
        return animation;
    }

    static void loadAnimations(std::map<std::string, std::array<int, 4>> animations, Entity *e)
    {
        for (const auto &[name, values] : animations) {
            Animation animation = createAnimation(name, values[0], values[1], values[2], values[3]);
            e->getComponent<AnimationComponent>()->addAnimation(name, animation);
            std::cout << name << " " << values[0] << " " << values[1] << " " << values[2] << " "
                      << values[3] << std::endl;
        }
    }
};
