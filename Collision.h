#pragma once
#include "vector2d.h"
#include <SDL.h>
#include <utility>
class Collision
{
public:
    static bool AABB(SDL_Rect rectA, SDL_Rect rectB)
    {
        if (rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x
            && rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y

        ) {
            return true;
        }
        return false;
    }
    static bool RayVSRect(Vector2D &rayOrigin,
                          Vector2D &rayDir,
                          SDL_Rect &rect,
                          Vector2D &contact_point,
                          Vector2D &contact_normal,
                          float &t_hit_near,
                          float &t_hit_far)
    {
        Vector2D t_near = (Vector2D(rect.x, rect.y) - rayOrigin) / rayDir;
        Vector2D t_far = (Vector2D(rect.x, rect.y) + Vector2D(rect.w, rect.h) - rayOrigin) / rayDir;

        if (t_near.x > t_far.x) {
            std::swap(t_near.x, t_far.x);
        }
        if (t_near.y > t_far.y) {
            std::swap(t_near.y, t_far.y);
        }
        if (t_near.x > t_far.y || t_near.y > t_far.x) {
            return false;
        }

        t_hit_near = std::max(t_near.x, t_near.y);
        t_hit_far = std::min(t_far.x, t_far.y);

        if (t_hit_far < 0 or t_hit_near < 0) {
            return false;
        }
        if (std::isnan(t_near.x) || std::isnan(t_near.y)) {
            return false;
        }
        if (std::isnan(t_far.x) || std::isnan(t_far.y)) {
            return false;
        }

        contact_point = rayOrigin + rayDir * t_hit_near;

        if (t_near.x > t_near.y) {
            if (rayDir.x < 0) {
                contact_normal = {1, 0};
            } else {
                contact_normal = {-1, 0};
            }

        } else if (t_near.x < t_near.y) {
            if (rayDir.y < 0) {
                contact_normal = {0, 1};
            } else {
                contact_normal = {0, -1};
            }
        }
        return true;
    }
    static bool DynamicRayVSRect(SDL_Rect &rect_origin,
                                 SDL_Rect &rect,
                                 const Vector2D &velocity,
                                 Vector2D &contact_normal,
                                 Vector2D &contact_point,
                                 float &t_near,
                                 float &t_far)
    {
        if (velocity.x == 0 && velocity.y == 0) {
            return false;
        }

        Vector2D origin = {static_cast<float>(rect_origin.x + rect_origin.w / 2),
                           static_cast<float>(rect_origin.y + rect_origin.h / 2)};
        Vector2D dest = velocity;

        if (RayVSRect(origin, dest, rect, contact_point, contact_normal, t_near, t_far)
            && t_near < 1) {
            return true;
        }

        return false;
    }
};
