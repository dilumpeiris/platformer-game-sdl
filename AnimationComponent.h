#pragma once
#include "ECS.h"
#include <SDL.h>
#include <map>

struct Animation
{
    double frame_speed;
    bool flipped = false;

    std::vector<SDL_Rect> source_rects;

    Animation()
        : frame_speed(0){};

    Animation(std::vector<SDL_Rect> sources, int frame_speed, bool flipped = false)
        : source_rects(sources)
        , frame_speed(frame_speed)
        , flipped(flipped)
    {}
};

class AnimationComponent : public Component
{
public:
    std::map<std::string, Animation> animations;
    std::string current_animation;
    int current_frame = 0;

    Uint32 lastFrameTime = 0;

    AnimationComponent() {}

    bool isAnimationFlipped() { return animations[current_animation].flipped; }

    void addAnimation(const std::string &name, Animation animation)
    {
        animations[name] = animation;
    }

    void playAnimation(const std::string &name)
    {
        if (current_animation != name) {
            current_animation = name;
            current_frame = 0;
            lastFrameTime = 0;
        }
    }
    SDL_Rect getCurrentFrame() { return animations[current_animation].source_rects[current_frame]; }

    void update() override
    {
        if (animations.find(current_animation) != animations.end()) {
            // Do we have to create two variables here?
            Uint32 current_time = SDL_GetTicks();
            Animation &anim = animations[current_animation];
            if (current_time - lastFrameTime >= anim.frame_speed) {
                current_frame = (current_frame + 1) % anim.source_rects.size();
                lastFrameTime = current_time;
            }
        }
    }
};
