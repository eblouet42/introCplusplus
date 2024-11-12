#pragma once

#include "Vec3.h"

using Color = Vec3;

struct Image
{
    static constexpr int width = 384;
    static constexpr int height = 256;

    Color pixels[width*height];

    const Color& operator()(int x, int y) const
    {
        return pixels[y*width + x];
    }
    Color& operator()(int x, int y)
    {
        return pixels[y*width + x];
    }
};

// @todo : provide the filename as argument !
void writeImagePPM(const Image& image);