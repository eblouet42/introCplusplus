#include "Intersection.h"

float intersect(const Ray& ray, const Sphere& sphere)
{
    //TODO make it more robust....
    Vec3 oc = sphere.center - ray.origin;
    auto a = dot(ray.direction, ray.direction);
    auto b = -2.0F * dot(ray.direction, oc);
    auto c = dot(oc, oc) - sphere.radius*sphere.radius;
    auto discriminant = b*b - 4.0F*a*c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0F*a);
    }
}

Intersection intersect(const Ray& ray, const Sphere spheres[], int num_spheres)
{
    Intersection intersection{};

    for (int id = 0; id<num_spheres; ++id) {
        float t_sphere = intersect(ray, spheres[id]);
        if (t_sphere>=0.0F && t_sphere<intersection.t_min) {
            intersection.t_min = t_sphere;
            intersection.sphere_id = id;
        }
    }

    return intersection;
}
