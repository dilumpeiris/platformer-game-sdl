#pragma once
#include "ECS.h"
#include <SDL.h>
#include <map>

struct Animation
{
    std::vector<std::string> frames;
    double frame_speed;
    Animation()
        : frame_speed(0)
    {}
    Animation(std::vector<std::string> frames, int frame_speed)
        : frames(frames)
        , frame_speed(frame_speed)
    {}
};

class AnimationComponent : public Component
{
public:
    std::map<std::string, Animation> animations;
    std::string current_animation;
    int state = 0;
    int current_frame = 0;
    Uint32 lastFrameTime = 0;

    AnimationComponent() {}

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
    std::string getCurrentFrame() { return animations[current_animation].frames[current_frame]; }
    void update() override
    {
        if (animations.find(current_animation) != animations.end()) {
            Uint32 current_time = SDL_GetTicks();
            Animation &anim = animations[current_animation];
            if (current_time - lastFrameTime >= anim.frame_speed) {
                current_frame = (current_frame + 1) % anim.frames.size();
                lastFrameTime = current_time;
            }
        }
    }
};
