#pragma once

#include "Vec3.hpp"

namespace rc::math
{
    inline Vec3 colorToVec3(int r, int g, int b)
    {
        return Vec3(static_cast<float>(r) / 255.f,
                    static_cast<float>(g) / 255.f,
                    static_cast<float>(b) / 255.f);
    }

    inline float min(float a, float b)
    {
        return a < b ? a : b;
    }

    inline Vec3 min(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.x < b.x ? a.x : b.x,
                    a.y < b.y ? a.y : b.y,
                    a.z < b.z ? a.z : b.z);
    }

    inline float max(float a, float b)
    {
        return a > b ? a : b;
    }

    inline Vec3 max(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.x > b.x ? a.x : b.x,
                    a.y > b.y ? a.y : b.y,
                    a.z > b.z ? a.z : b.z);
    }

    template<class T, class T2>
    inline T clamp(const T& x, const T2& a, const T2& b)
    {
        return min(max(x, T(a)), T(b));
    }

    template<class T, class T2>
    inline T lerp(const T& x, const T& y, const T2& a)
    {
        return x * (1.f - a) + y * a;
    }
}
