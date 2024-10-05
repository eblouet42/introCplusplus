#include "vec3.cpp"
using Color = vec3;

struct Image{
  static int width;
  static int height;
  Color data[width][height];
};