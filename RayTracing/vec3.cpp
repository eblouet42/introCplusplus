#include <cmath>
#include <ostream>
#include <iostream>

struct vec3{float coord[3];};

float dot(vec3 a, vec3 b){
  return a.coord[0] * b.coord[0] + a.coord[1] * b.coord[1] + a.coord[2] * b.coord[2];
};
vec3 cross(vec3 a, vec3 b){
  vec3 result;
  result.coord[0] = a.coord[1] * b.coord[2] - a.coord[2] * b.coord[1];
  result.coord[1] = a.coord[2] * b.coord[0] - a.coord[0] * b.coord[2];
  result.coord[2] = a.coord[0] * b.coord[1] - a.coord[1] * b.coord[0];
  return result;
}
float length(vec3 a){
  return sqrt(dot(a,a));
}
float squaredLength(vec3 a){
  return dot(a,a);
}
inline vec3 operator+(const vec3& v0, const vec3& v1) {
  vec3 result;
  result.coord[0] = v0.coord[0] + v1.coord[0];
  result.coord[1] = v0.coord[1] + v1.coord[1];
  result.coord[2] = v0.coord[2] + v1.coord[2];
}
inline vec3 operator-(const vec3& v0, const vec3& v1) {
  vec3 result;
  result.coord[0] = v0.coord[0] - v1.coord[0];
  result.coord[1] = v0.coord[1] - v1.coord[1];
  result.coord[2] = v0.coord[2] - v1.coord[2];
}
inline vec3 operator*(float scalar, const vec3& v) {
  vec3 result;
  result.coord[0] = scalar * v.coord[0];
  result.coord[1] = scalar * v.coord[1];
  result.coord[2] = scalar * v.coord[2];
}
inline vec3 operator*(const vec3& v,float scalar) {
  vec3 result;
  result.coord[0] = scalar * v.coord[0];
  result.coord[1] = scalar * v.coord[1];
  result.coord[2] = scalar * v.coord[2];
}
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  out << "{ " << v.coord[0]<< " , " << v.coord[1]<< " , " << v.coord[2]<< " }";
  return out;
}

/*
  int main() {
  vec3 v1 = {1,2,3};
  vec3 v2 = {4,5,6};
  std::cout<<"v1.v2 = "<<dot(v1,v2)<<std::endl;
  std::cout<<"v1^v2 = "<<cross(v1,v2)<<std::endl;
  std::cout<<"||v1|| = "<<length(v1)<<std::endl;
  std::cout<<"uwu"<<std::endl;
  std::cout<<"||v2||^2 = "<<squaredLength(v2)<<std::endl;
}
*/