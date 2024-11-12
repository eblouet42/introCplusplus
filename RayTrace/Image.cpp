#include "Image.h"

#include <fstream>

void writeColor(std::ostream& stream, const Color& color)
{
    // Convert from scalar in [0,1] to integer in [0,255]
    int red = int(255.0 * color.components[0]);
    int green = int(255.0 * color.components[1]);
    int blue = int(255.0 * color.components[2]);

    stream << red << ' ' << green << ' ' << blue << '\n';
}

void writeImagePPM(const Image& image)
{
    std::ofstream file_stream{"C:/Users/evanb/CLionProjects/introCplusplus/RayTrace/output.ppm"};
    file_stream << "P3\n" << image.width << " " << image.height << "\n255\n";

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            writeColor(file_stream, image(i,j));
        }
    }
}