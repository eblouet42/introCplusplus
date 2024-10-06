#include "vec3.cpp"
#include <fstream>

using Color = vec3;

struct Image{
  static constexpr int width=384;
  static constexpr int height=256;
  Color data[width*height];
  const Color& operator() (int x, int y) const {
    return data[y*width+x];
  }
  Color& operator()(int x, int y) {
    return data[y*width+x];
  }
};

void createImage(const Image& image, const std::string& filename) {
  std::ofstream out(filename.c_str());
  out << "P3\n" << image.width << " " << image.height << "\n255\n";
  for (int y = 0; y < image.height; ++y) {
    for (int x = 0; x < image.width; ++x) {
      out << int(image(x,y).coord[0]*255) << " "<<int(image(x,y).coord[1]*255)<<" "<<int(image(x,y).coord[2]*255)<<"\n";
    }
  }
}
int main(){
  Image image;
  for (float y = 0; y < image.height; ++y) {
    for (float x = 0; x < image.width; ++x) {
      Color pixel = {0,x/image.width,0};
      image(x,y) = pixel;
    }
  }
  createImage(image,"degradeVertHorizontal.ppm");
  for (float y = 0; y < image.height; ++y) {
    for (float x = 0; x < image.width; ++x) {
      Color pixel = {0,0,x/image.width};
      image(x,y) = pixel;
    }
  }
  createImage(image,"degradeBleuHorizontal.ppm");
  for (float y = 0; y < image.height; ++y) {
    for (float x = 0; x < image.width; ++x) {
      Color pixel = {y/image.height,0,0};
      image(x,y) = pixel;
    }
  }
  createImage(image,"degradeRougeVertical.ppm");
  for (float y = 0; y < image.height; ++y) {
    for (float x = 0; x < image.width; ++x) {
      Color pixel = {0,(x*y)/(image.width*image.height),(x*y)/(image.width*image.height)};
      image(x,y) = pixel;
    }
  }
  createImage(image,"degradeCyanDiagonal.ppm");
  for (float y = 0; y < image.height; ++y) {
    for (float x = 0; x < image.width; ++x) {
      Color pixel = {1-(x+y)/(image.width+image.height),0,(x+y)/(image.width+image.height)};
      image(x,y) = pixel;
    }
  }
  createImage(image,"rougeBleu.ppm");
  for (float y = 0; y < image.height; ++y) {
    for (float x = 0; x < image.width; ++x) {
      Color pixel;
      if (y/image.height*3<1) {
        pixel = {0,0,0};
      } else if (y/image.height*3<2) {
        pixel = {1,1,1};
      } else {
        pixel = {0,0.5,0};
      }
      if (x<image.height/2) {
        if (y<image.height/2) {
          if (x<y) {
            pixel = {0.85,0,0};
          }
        }
        else {
          if (x<(image.height-y)) {
            pixel = {0.85,0,0};
          }
        }
      }
      image(x,y) = pixel;
    }
  }
  createImage(image,"islamoGauchiste.ppm");
  return 666;
}
