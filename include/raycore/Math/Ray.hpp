#pragma once

#include <raycore\Math\Vec3.hpp>

namespace rc::math
{
    struct Ray
    {
        Vec3 origin;
        Vec3 direction;
        
        Ray();
        Ray(const Vec3& origin, const Vec3& dir);
        Ray(const Ray& ray);

        Vec3 at(float t) const;
    };

    inline Ray::Ray()
    {
    }

    inline Ray::Ray(const Vec3& origin, const Vec3& dir) :
        origin(origin),
        direction(dir)
    {
    }

    inline Ray::Ray(const Ray& ray) :
        origin(ray.origin),
        direction(ray.direction)
    {
    }

    inline Vec3 Ray::at(float t) const
    {
        return origin + t * direction;
    }
}
