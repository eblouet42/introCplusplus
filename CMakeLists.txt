cmake_minimum_required(VERSION 3.29)
project(introCplusplus)

set(CMAKE_CXX_STANDARD 23)


add_executable(introCplusplus main.cpp)
add_executable(measure_runtime runtime.cpp)
add_executable(computation Computation.cpp)
add_executable(string cstring.cpp)
add_executable(vec3 RayTracing/vec3.cpp)
add_executable(image RayTracing/image.cpp)
