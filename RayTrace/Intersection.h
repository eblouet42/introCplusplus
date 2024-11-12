#pragma once
#include "Geometry.h"
#include "Ray.h"

float intersect(const Ray& ray, const Sphere& sphere);

struct Intersection
{
    float t_min = std::numeric_limits<float>::infinity();
    int sphere_id = -1;
};

Intersection intersect(const Ray& ray, const Sphere spheres[], int num_spheres);
