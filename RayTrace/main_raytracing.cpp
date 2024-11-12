

#include "Image.h"
#include "Intersection.h"
#include "Ray.h"


int main()
{
    Image image;
    constexpr int num_spheres = 6;
    Sphere spheres[num_spheres] = {
        { .center = {{ 0, 0, 5 }}, .radius = 0.3 },
        { .center = {{ -0.35, 0, 5 }}, .radius = 0.2 },
        { .center = {{ 0.45, 0.35, 5 }}, .radius = 0.1 },
        { .center = {{ 1.0, 1.0, 5 }}, .radius = 0.1 },
        { .center = {{ -1, -1, 5 }}, .radius = 0.5 },
        { .center = {{ 1.25, -0.25, 5 }}, .radius = 0.6 }
        };

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {

            float x = 2.0F*static_cast<float>(i) / static_cast<float>(image.height-1) - 1.0F;
            float y = 2.0F*static_cast<float>(j) / static_cast<float>(image.height-1) - 1.0F;

            Ray ray = { .origin = { x, y, 0 }, .direction = { 0, 0, 1 } };
            Intersection intersection = intersect(ray, spheres, num_spheres);
            if (intersection.sphere_id>=0) {
                // image(i,j) = Color{{1.0F,0.0F,0.0F}};
                Vec3 normal = normalFromPosition(spheres[intersection.sphere_id],
                                                 ray.origin + intersection.t_min*ray.direction);
                Color color = 0.5* Color{{ normal[0]+1, normal[1]+1, normal[2]+1 }};
                image(i,j) = color;
            } else {
                image(i,j) = Color{{1.0F,1.0F,1.0F}};
            }
        }
    }

    writeImagePPM(image);
}
