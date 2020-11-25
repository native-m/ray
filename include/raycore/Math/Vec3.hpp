#pragma once

#include <cmath>

namespace rc::math
{
    struct Vec3
    {
        float x, y, z;

        Vec3();
        Vec3(float s);
        explicit Vec3(float x, float y, float z);
        Vec3(const Vec3& v);

        Vec3& operator=(float s);
        Vec3& operator=(const Vec3& v);

        Vec3& operator+=(const Vec3& v);
        Vec3& operator-=(const Vec3& v);
        Vec3& operator*=(const Vec3& v);
        Vec3& operator/=(const Vec3& v);

        Vec3& operator+=(float s);
        Vec3& operator-=(float s);
        Vec3& operator*=(float s);
        Vec3& operator/=(float s);
    };

    inline Vec3::Vec3() :
        x(0), y(0), z(0)
    {
    }

    inline Vec3::Vec3(float s) :
        x(s), y(s), z(s)
    {
    }

    inline Vec3::Vec3(float x, float y, float z) :
        x(x), y(y), z(z)
    {
    }

    inline Vec3::Vec3(const Vec3& v) :
        x(v.x), y(v.y), z(v.z)
    {
    }

    inline Vec3& Vec3::operator=(float s)
    {
        x = s;
        y = s;
        z = s;

        return *this;
    }

    inline Vec3& Vec3::operator=(const Vec3& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }

    inline Vec3& Vec3::operator+=(const Vec3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    inline Vec3& Vec3::operator-=(const Vec3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return *this;
    }

    inline Vec3& Vec3::operator*=(const Vec3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;

        return *this;
    }

    inline Vec3& Vec3::operator/=(const Vec3& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;

        return *this;
    }

    inline Vec3& Vec3::operator+=(float s)
    {
        x += s;
        y += s;
        z += s;

        return *this;
    }

    inline Vec3& Vec3::operator-=(float s)
    {
        x -= s;
        y -= s;
        z -= s;

        return *this;
    }

    inline Vec3& Vec3::operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;

        return *this;
    }

    inline Vec3& Vec3::operator/=(float s)
    {
        float r = 1.f / s;
        x *= r;
        y *= r;
        z *= r;

        return *this;
    }

    inline Vec3 operator+(const Vec3& v)
    {
        return Vec3(v.x, v.y, v.z);
    }

    inline Vec3 operator-(const Vec3& v)
    {
        return Vec3(-v.x, -v.y, -v.z);
    }

    inline Vec3 operator+(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    inline Vec3 operator-(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    inline Vec3 operator*(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    inline Vec3 operator/(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    inline Vec3 operator+(const Vec3& a, float s)
    {
        return Vec3(a.x + s, a.y + s, a.z + s);
    }

    inline Vec3 operator-(const Vec3& a, float s)
    {
        return Vec3(a.x - s, a.y - s, a.z - s);
    }

    inline Vec3 operator*(const Vec3& a, float s)
    {
        return Vec3(a.x * s, a.y * s, a.z * s);
    }

    inline Vec3 operator/(const Vec3& a, float s)
    {
        float r = 1.f / s;
        return Vec3(a.x * r, a.y * r, a.z * r);
    }

    inline Vec3 operator+(float s, const Vec3& b)
    {
        return Vec3(s + b.x, s + b.y, s + b.z);
    }

    inline Vec3 operator-(float s, const Vec3& b)
    {
        return Vec3(s - b.x, s - b.y, s - b.z);
    }

    inline Vec3 operator*(float s, const Vec3& b)
    {
        return Vec3(s * b.x, s * b.y, s * b.z);
    }

    inline Vec3 operator/(float s, const Vec3& b)
    {
        return Vec3(s / b.x, s / b.y, s / b.z);
    }

    inline float dot(const Vec3& a, const Vec3& b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    inline float lengthSq(const Vec3& v)
    {
        return dot(v, v);
    }

    inline float length(const Vec3& v)
    {
        return std::sqrt(dot(v, v));
    }

    inline Vec3 normalize(const Vec3& v)
    {
        float r = 1.f / length(v);
        return Vec3(v.x * r, v.y * r, v.z * r);
    }

    inline Vec3 cross(const Vec3& a, const Vec3& b)
    {
        return Vec3(a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x);
    }
}
