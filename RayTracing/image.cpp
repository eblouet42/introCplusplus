#include "vec3.cpp"
#include <fstream>

using Color = vec3;

struct Image{
  static constexpr int width=384;
  static constexpr int height=384;
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

struct Ray {
  vec3 origin;
  vec3 direction;
};

struct Sphere{
  vec3 center;
  float radius;
};

double intersect(const Ray& ray,const Sphere& sphere){
  vec3 oc=sphere.center-ray.origin;
  double a=dot(ray.direction,ray.direction);
  double b=2*dot(ray.direction,oc);
  double c=dot(oc,oc)-sphere.radius*sphere.radius;
  double discr=b*b-4*a*c;
  if(discr<0) {return -1.0f;}
  float dis=sqrt(discr);
  return (-b-dis)/(2*a);
}

void rayTracingOneSphere(Image& image, const Sphere& sphere) {
  vec3 desuns={1,1,1};
  for (int y = 0; y < image.height; ++y) {
    for (int x = 0; x < image.width; ++x) {
      Ray ray={{2.0f*x/image.width-1.0f,2.0f*y/image.height-1.0f,0},{0,0,1.0f}};
      float t=intersect(ray,sphere);
      if (t>=0){
        vec3 hit_point = ray.origin+t*ray.direction;
        vec3 normal = (hit_point - sphere.center)*(1/length(hit_point-sphere.center));
        Color pixel=0.5f*(normal+desuns);
        image(x,y)=pixel;
      }
      else {
        Color pixel={1,1,1};
        image(x,y)=pixel;
      }
    }
  }
}



int main(){
  Image image;

  /*

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
  createImage(image,"islamoGauchiste.ppm");*/
  Sphere sphere={{0,0,-20},0.8f};
  rayTracingOneSphere(image,sphere);
  createImage(image,"testsphere.ppm");
  return 666;
}
