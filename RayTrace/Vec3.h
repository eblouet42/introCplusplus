#pragma once

#include <cmath>
#include <iostream>

struct Vec3
{
    float components[3] = { 0.0, 0.0, 0.0 };

    // allow to write : Vec3 vec; vec[i];
    float operator[](int i) const { return components[i]; }
};

inline float dot(const Vec3& v0, const Vec3& v1)
{
    return v0.components[0] * v1.components[0]
         + v0.components[1] * v1.components[1]
         + v0.components[2] * v1.components[2];
}

inline Vec3 cross(const Vec3& v0, const Vec3& v1)
{
    return {v0.components[1] * v1.components[2] - v0.components[2] * v1.components[1],
                v0.components[2] * v1.components[0] - v0.components[0] * v1.components[2],
                v0.components[0] * v1.components[1] - v0.components[1] * v1.components[0] };
}

inline float squaredLength(const Vec3& v)
{
    return v.components[0] * v.components[0]
         + v.components[1] * v.components[1]
         + v.components[2] * v.components[2];
}

inline float length(const Vec3& p)
{
    return std::sqrt(squaredLength(p));
}

inline Vec3 operator-(const Vec3 &v) { return {-v.components[0], -v.components[1], -v.components[2] }; }

inline Vec3 operator+(const Vec3& v0, const Vec3& v1) {
    return {{ v0.components[0] + v1.components[0], v0.components[1] + v1.components[1], v0.components[2] + v1.components[2] }};
}

inline Vec3 operator-(const Vec3& v0, const Vec3& v1) {
    return {{ v0.components[0] - v1.components[0], v0.components[1] - v1.components[1], v0.components[2] - v1.components[2]}};
}
inline Vec3 operator*(float t, const Vec3& v) {
    return {{t*v.components[0], t*v.components[1], t*v.components[2] }};
}

inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
    return out << v.components[0] << " " << v.components[1] << " " << v.components[2];
}
