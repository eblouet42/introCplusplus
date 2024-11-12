#pragma once

#include "Vec3.h"

struct Sphere
{
    Vec3 center = {{ 0.0F, 0.0F, 0.0F}};;
    float radius = 1.0F;
};

inline Vec3 normalFromPosition(const Sphere &sphere, const Vec3 &position)
{
    Vec3 normal = sphere.center - position;
    normal = (1.0F/length(normal)) * normal;
    return normal;
}